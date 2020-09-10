##########################################################################################
# SRC_URI - Couldn't find how to deal with multiple git repos:
# 1. Tried and it didn't work: http://lists.linuxtogo.org/pipermail/openembedded-core/2011-October/010926.html
# 2. No *.bb examples found
# Overriding do_fetch:

do_fetch(){
  echo "Fetching ezynq..."
  if [ ! -d "${GITDIR_ezynq}/.git" ]; then
    # if anything left after do_clean - delete it
    if [ -d ${GITDIR_ezynq} ]; then
	rm -r ${GITDIR_ezynq}
    fi
    git clone -b ${SRC_URI_ezynq_branch} ${SRC_URI_ezynq} ${GITDIR_ezynq}
    cd ${GITDIR_ezynq}
    git checkout ${SRCREV_ezynq}
    cd ${WORKDIR}
    echo "Cloning ezynq done."
  else
    echo "Skipped: ezynq is already cloned."
  fi

  echo "Fetching ${GITDIR_uboot_dir}..."
  if [ ! -d "${GITDIR_uboot}/.git" ]; then
    # not really needed - for consistency
    if [ -d ${GITDIR_uboot} ]; then
	rm -r ${GITDIR_uboot}
    fi
    git clone -b ${SRC_URI_uboot_branch} ${SRC_URI_uboot} ${GITDIR_uboot}
    cd ${GITDIR_uboot}
    git checkout ${SRCREV_uboot}
    cd ${WORKDIR}
    echo "Cloning ${GITDIR_uboot_dir} done."
  else
    echo "Skipped: ${GITDIR_uboot_dir} is already cloned."
  fi
}

##########################################################################################
# In the overridden do_unpack() a patch file is created

do_unpack(){
  echo "Linking and creating a patch file..."

  if [ ! -h "${GITDIR_uboot}/${GITDIR_ezynq_label}" ]; then
    ln -s ${GITDIR_ezynq} "${GITDIR_uboot}/${GITDIR_ezynq_label}"
  fi  

  if [ ! -f "${GITDIR_ezynq}/${PATCH_NAME}" ]; then
    cd ${GITDIR_ezynq}
    diff -rubPB "${GITDIR_uboot_dir}" "${GITDIR_ezynq_u-boot-tree}" > "${PATCH_NAME}" || exit 0
    cd ${WORKDIR}
    echo "Done."
  else
    echo "Already exists."
  fi
}

##########################################################################################
# overriding do_patch()

do_patch(){
  echo "Applying the patch..."
  cd ${GITDIR_uboot}
  patch -r - -Np1 < "../${PATCH_NAME}" || exit 0
  cd ${WORKDIR}
}
##########################################################################################
#overriding do_configure()

do_configure(){
  echo "Configuring..."
  cd ${GITDIR_uboot}
  #no need to source init_env
  #. ./init_env
  oe_runmake clean
  oe_runmake ${UBOOT_MACHINE}
  oe_runmake include/autoconf.mk
  cd ${WORKDIR}
}

##########################################################################################
#overriding do_compile()

do_compile(){
  echo "Compiling..."
  cd ${GITDIR_uboot}

  echo "Running ezynqcfg.py for the first time - u-boot length is not known yet, generating arch/arm/mach-zynq/ezynq.c"

  ${GITDIR_ezynq_label}/ezynqcfg.py -c include/autoconf.mk --html u-boot.html -o boot_head.bin --html-mask 0x3ff --lowlevel arch/arm/mach-zynq/ezynq.c

  unset LDFLAGS
  unset CFLAGS
  unset CPPFLAGS
  oe_runmake

  echo "Running ezynqcfg.py for the second time - u-boot length is known and will be used in the RBL header"

  echo "Other files are already created, repeating it here just to remind their paths"

  if [ $(cat .config | grep "CONFIG_SPL_OF_CONTROL=y") ]; then
    UBOOT_FILE="spl/u-boot-spl-dtb.bin"
  elif [ $(cat .config | grep "CONFIG_SPL=y") ]; then
    UBOOT_FILE="spl/u-boot-spl.bin"
  else
    UBOOT_FILE="u-boot.bin"
  fi

  ${GITDIR_ezynq_label}/ezynqcfg.py -c include/autoconf.mk -o boot_head.bin --uboot $UBOOT_FILE --html u-boot.html --html-mask 0x3ff --lowlevel arch/arm/mach-zynq/ezynq.c

  cat boot_head.bin $UBOOT_FILE > boot.bin

  oe_runmake env
  
  cd ${WORKDIR}
}

##########################################################################################
# do_deploy_append
do_deploy_append() {
    if [ $(cat ${S}/.config | grep "CONFIG_OF_CONTROL=y") ]; then
	rm -f ${DEPLOYDIR}/${UBOOT_BINARY}
	install ${S}/u-boot-dtb.img ${DEPLOYDIR}/${UBOOT_IMAGE}
	cd ${DEPLOYDIR}
	rm -f ${UBOOT_BINARY} ${UBOOT_SYMLINK} u-boot-dtb.img
	ln -sf ${UBOOT_IMAGE} ${UBOOT_SYMLINK}
	ln -sf ${UBOOT_IMAGE} u-boot-dtb.img
	for RLOC in ${PRODUCTION_ROOT_LOCATION}; do
		if [ ! -d ${RLOC} ]; then
			mkdir ${RLOC}
		fi
		if [ -f ${RLOC}/${PRODUCTION_BOOT} ]; then
			rm ${RLOC}/${PRODUCTION_BOOT}
		fi
		cp ${SPL_IMAGE} ${RLOC}/${PRODUCTION_BOOT}
		if [ -f ${RLOC}/${PRODUCTION_UBOOT} ]; then
			rm ${RLOC}/${PRODUCTION_UBOOT}
		fi
		cp ${UBOOT_IMAGE} ${RLOC}/${PRODUCTION_UBOOT}
	done
    fi
}


