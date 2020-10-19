UBOOT_VERSION = "v2020.01"
KUSH_RELEASE_VERSION = "v2020.1"

UBRANCH ?= "warrior"

SRCREV ?= "72843922e8a0b9b575d4e6179ca9bdfb2badb1c5"

include u-boot-kush.inc
#include u-boot-spl-zynq-init.inc

#SRC_URI_append_kc705-microblazeel = " file://microblaze-kc705-Convert-microblaze-generic-to-k.patch"

LICENSE = "GPLv2+"
LIC_FILES_CHKSUM = "file://README;md5=c3594536cc6d9b0ea2c2e559f6e530b7"

# u-boot-xlnx has support for these
HAS_PLATFORM_INIT ?= " \
		zinc_kush_defconfig \
		zynq_microzed_config \
		zynq_zed_config \
		zynq_zc702_config \
		zynq_zc706_config \
		zynq_zybo_config \
		xilinx_zynqmp_zcu102_rev1_0_config \
		xilinx_zynqmp_zcu106_revA_config \
		xilinx_zynqmp_zcu104_revC_config \
		xilinx_zynqmp_zcu100_revC_config \
		xilinx_zynqmp_zcu111_revA_config \
		xilinx_zynqmp_zc1275_revA_config \
		xilinx_zynqmp_zc1275_revB_config \
		xilinx_zynqmp_zc1254_revA_config \
		"

do_compile_append() {
bbdebug 3 "Shreyas.. do compile append invoked"
bbplain "shreyas..inside do compile append"
}
