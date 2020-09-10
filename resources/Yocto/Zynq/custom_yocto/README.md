# custom_yocto
This custom yocto is to build embedded build system for custom board similar to AVNET microzed zynq.
This is a custom build system because I have deviated from microzed AVNET ZYNQ to add some extensions.
In this yocto project, we have the machine called - "kush-zinc.conf".

### 1) checkout steps
git clone https://github.com/joshis1/custom_yocto.git   
git submodule update --init --recursive  

### 2) Environment setup  
$source poky/oe-init-build-env build-custom-zynq/  

### 3) Build Uboot

$bitbake -ccleansstate  virtual/bootloader  
$bitbake virtual/bootloader  

### 4) Build minimal image
$bitbake core-image-minimal  


# Kernel link

https://github.com/joshis1/kernel   


# Uboot link

https://github.com/joshis1/uboot  


# Important notes.
For Zynq platform you cannot run the uboot.elf directly you need to create boot.bin using fsbl.elf from the xilinx sdk.  
Ensure you have installed - $sudo apt-get install libssl1.0-dev otherwise bootgen won't compile.  



 
