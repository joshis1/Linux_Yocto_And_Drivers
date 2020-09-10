DESCRIPTION = "EZYNQ is the Xilinx's bootgen (fsbl) replacement + u-boot. The output is a working BOOT.BIN"
HOMEPAGE = "http://elphel.com;http://blog.elphel.com"
SECTION = "bootloaders"

#Project Version
PV = "v2016.05"
#Project Revision
PR = "r0"

include u-boot-ezynq.inc

PROVIDES = "u-boot virtual/bootloader"

inherit zynq7-platform-paths

#UBOOT_CONFIG="dtb"
