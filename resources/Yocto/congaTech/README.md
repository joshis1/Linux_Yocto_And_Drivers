# Yocto base image
This repository is to build Congatech Yocto base image. 

Getting Started
---------------
**Install Repo.**

Download the Repo script:

    $ curl https://storage.googleapis.com/git-repo-downloads/repo > repo

Make it executable:

    $ chmod a+x repo

Move it on to your system path:

    $ sudo mv repo /usr/local/bin/

If it is correctly installed, you should see a Usage message when invoked
with the help flag.

    $ repo --help

**Initialize a Repo client.**

Get this repository first

    $ git clone <git>
    $ cd yocto-recipes/
                                
Tell Repo where to find the manifest:

    $ repo init -u <git> -b main -m default.xml

Fetch all the repositories:

    $ repo sync

# How to build base Yocto image for Congatech?

Build Instructions

    $ source sources/poky/oe-init-build-env build/
    $ bitbake core-minimal

