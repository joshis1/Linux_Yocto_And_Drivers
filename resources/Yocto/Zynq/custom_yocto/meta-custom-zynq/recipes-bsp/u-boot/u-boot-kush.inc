require recipes-bsp/u-boot/u-boot.inc

DEPENDS += "bc-native dtc-native bison-native"

KUSH_RELEASE_VERSION ?= ""
UBOOT_VERSION_EXTENSION ?= "-kush-${KUSH_RELEASE_VERSION}"
PV = "${UBOOT_VERSION}${UBOOT_VERSION_EXTENSION}+git${SRCPV}"


UBOOTURI ?= "git://github.com/joshis1/uboot-microzed-kush-zynq.git;protocol=https"
UBRANCH ?= "warrior"
UBRANCHARG = "${@['nobranch=1', 'branch=${UBRANCH}'][d.getVar('UBRANCH', True) != '']}"

SRC_URI = "${UBOOTURI};${UBRANCHARG}"

S = "${WORKDIR}/git"

FILESEXTRAPATHS_prepend := "${THISDIR}/u-boot:"
FILESEXTRAPATHS_prepend := "${THISDIR}/u-boot-kush:"
FILESEXTRAPATHS_prepend := "${@'${THISDIR}/u-boot-kush/${KUSH_RELEASE_VERSION}:' if d.getVar('KUSH_RELEASE_VERSION') else ''}"

