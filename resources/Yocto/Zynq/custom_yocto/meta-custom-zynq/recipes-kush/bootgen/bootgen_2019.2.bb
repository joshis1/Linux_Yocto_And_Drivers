SUMMARY = "Xilinx bootgen utility"
DESCRIPTION = "Generates boot images for Xilinx devices"
HOMEPAGE = "https://github.com/Xilinx/bootgen"

CXXFLAGS = "-std=c++0x -O -Wall -Wno-reorder -Wno-deprecated-declarations"

BOOTGEN_DIR = "git"

LICENSE = "Apache-2.0 & openssl"
LIC_FILES_CHKSUM = "file://${BOOTGEN_DIR}/LICENSE;md5=c979df673927004a489691fc457facff"

SRC_URI = "git://github.com/Xilinx/bootgen.git;protocol=https;tag=${PV};name=bootgen"

SRC_URI[bootgen.md5sum] = "abe3e03e469c542d8e157cdd93f4d8a6"
SRC_URI[bootgen.sha256sum] = "6957c20e82561ac4231638996e74f4cfa4e6faabc5a2f511f0b4e3940e8f7b12"

S = "${WORKDIR}"


do_compile() {
    bbplain "shreyas..the S is " + ${S}
    bbplain "shreyas..the BOOTGEN_DIR is " + ${BOOTGEN_DIR}
    oe_runmake -C ${BOOTGEN_DIR}
}


BBCLASSEXTEND += "native nativesdk"
