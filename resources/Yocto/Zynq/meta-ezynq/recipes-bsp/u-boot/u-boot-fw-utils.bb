DESCRIPTION = "EZYNQ is the Xilinx's bootgen (fsbl) replacement + u-boot. The output is a working BOOT.BIN"
HOMEPAGE = "http://elphel.com;http://blog.elphel.com"
SECTION = "bootloaders"

#Project Version
PV = "v2016.05"
#Project Revision
PR = "r0"

include u-boot-ezynq.inc

#PROVIDES = "u-boot virtual/bootloader"

inherit zynq7-platform-paths

INSANE_SKIP_${PN} = "already-stripped"

#UBOOT_CONFIG="dtb"

PROVIDES = "u-boot-fw-utils"
PACKAGES = "u-boot-fw-utils"

FILES_${PN} += "\
           /sbin/* \
          "

do_install_append(){
    install -d ${D}${base_sbindir}
    install -d ${D}${sysconfdir}
    install -m 755 ${S}/tools/env/fw_printenv ${D}${base_sbindir}/fw_printenv
    install -m 755 ${S}/tools/env/fw_printenv ${D}${base_sbindir}/fw_setenv
    install -m 0644 ${S}/tools/env/fw_env.config ${D}${sysconfdir}/fw_env.config
}

PACKAGE_ARCH = "${MACHINE_ARCH}"
BBCLASSEXTEND = "cross"
