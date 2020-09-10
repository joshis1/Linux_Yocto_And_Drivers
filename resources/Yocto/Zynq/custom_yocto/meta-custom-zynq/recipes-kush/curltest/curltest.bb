SUMMARY = "Simple Hello World Application"
DESCRIPTION = "A test application to demonstrate how to create a recipe \
               by directly compiling C files with BitBake."

SECTION = "examples"
PRIORITY = "optional"

LICENSE = "MIT"
LIC_FILES_CHKSUM = "\
   file://README.txt;md5=321180101a13e8916e6753497a4f9c82"

SRC_URI = "file://test.c \
           file://Makefile \
           file://README.txt"

S = "${WORKDIR}"

DEPENDS += " \
    curl \
    openssl \
"

CFLAGS += "-c -g"

LDFLAGS += "-lpthread -lcurl -lssl"

EXTRA_OEMAKE = "'CFLAGS=${CFLAGS}' 'LDFLAGS=${LDFLAGS}'"


do_compile() {
    oe_runmake
}

do_install() {
    install -d ${D}${bindir}
    install -m 0755 test-curl ${D}${bindir}
}
