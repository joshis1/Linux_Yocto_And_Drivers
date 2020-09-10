SUMMARY = "Simple Hello World Application"
DESCRIPTION = "A test application to demonstrate how to create a recipe \
               by directly compiling C files with BitBake."

SECTION = "examples"
PRIORITY = "optional"

LICENSE = "MIT"
LIC_FILES_CHKSUM = "\
   file://README.txt;md5=321180101a13e8916e6753497a4f9c82"

SRC_URI = "file://helloprint.c \
           file://hello.c \
           file://helloprint.h \
           file://README.txt"

S = "${WORKDIR}"

do_compile() {
   ${CC} -c helloprint.c
    ${CC} -c hello.c
    ${CC} ${CFLAGS} ${LDFLAGS} -o hello hello.o helloprint.o
#    ${CC} ${CFLAGS} ${LDFLAGS} -o hello helloprint.c hello.c 
}

do_install() {
    install -d ${D}${bindir}
    install -m 0755 hello ${D}${bindir}
}
