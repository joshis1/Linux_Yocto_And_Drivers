require recipes-bsp/u-boot/u-boot.inc

LICENSE = "GPLv2+ & GPLv3"
LIC_FILES_CHKSUM = "file://${GITDIR_uboot}/README;md5=f0b2103a037ad81f10894cc74e3b6212 \
		    file://${GITDIR_ezynq}/LICENSE;md5=891e49b3c2a8c133ffe7985e54245aff"

# working directory
S = "${WORKDIR}/git/${GITDIR_uboot_dir}"

PACKAGE_ARCH = "${MACHINE_ARCH}"

##########################################################################################
# Defining u-boot.inc parameters

UBOOT_SUFFIX = "img"
UBOOT_IMAGE = "u-boot-${MACHINE}-${PV}-${PR}.${UBOOT_SUFFIX}"
UBOOT_BINARY = "u-boot.${UBOOT_SUFFIX}"
UBOOT_SYMLINK = "u-boot-${MACHINE}.${UBOOT_SUFFIX}"
UBOOT_MAKE_TARGET = "all"

SPL_SUFFIX = "bin"
SPL_BINARY = "boot.${SPL_SUFFIX}"
SPL_IMAGE = "boot-${MACHINE}-${PV}-${PR}.${SPL_SUFFIX}"
SPL_SYMLINK = "boot-${MACHINE}.${SPL_SUFFIX}"

##########################################################################################
# Variables used in the below overridden functions
GITDIR_ezynq_dir= "git"
GITDIR_ezynq_label = "ezynq"
GITDIR_ezynq= "${WORKDIR}/${GITDIR_ezynq_dir}"
GITDIR_ezynq_u-boot-tree= "${GITDIR_ezynq}/u-boot-tree"

GITDIR_uboot_dir= "u-boot"
GITDIR_uboot= "${WORKDIR}/git/${GITDIR_uboot_dir}"

ELPHELGITHOST ??= "git.elphel.com"

SRC_URI_ezynq= "https://${ELPHELGITHOST}/Elphel/ezynq.git"
SRC_URI_ezynq_branch= "master"

SRC_URI_uboot= "git://git.denx.de/u-boot.git"
#for u-boot-xlnx
#SRC_URI_uboot= "https://github.com/Xilinx/u-boot-xlnx.git"
SRC_URI_uboot_branch= "master"

#SRCREV_ezynq= "83340698f9669977b7205aa67e6ca0dd23fb741f"
#SRCREV_ezynq= "89bb3ac2ed47ae48460e4dd82829d765b7922269"
#SRCREV_ezynq= "80f478a416f48fc5dc0485bcee220bba6132acd3"
SRCREV_ezynq= ""

#SRCREV_uboot= "bbd91fc9ae290c31dc52fd8322f43f67ddd39247"
#SRCREV_uboot= "6742f65365086ded52fa9726c9120de8a6ad541b"
#SRCREV_uboot= "54fee227ef141214141a226efd17ae0516deaf32"
#SRCREV_uboot= "2a0536fa48db1fc5332e3cd33b846d0da0c8bc1e"
#SRCREV_uboot= "fa85e826c16b9ce1ad302a57e9c4b24db0d8b930"
SRCREV_uboot= "aeaec0e682f45b9e0c62c522fafea353931f73ed"
#for u-boot-xlnx
#SRCREV_uboot= "01b1fea9b13b799a16efd743587dc861719e5212"

PATCH_NAME= "ezynq.patch" 

include u-boot-ezynq-tasks.inc