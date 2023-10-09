# beaglebone
beaglebone samples based on BeagleBone Blue with Debian GNU/Linux 10 (buster)  and Linux kernel 4.19.94-ti-r42

/boot/uEnv.txt is configured as follows:


#Docs: http://elinux.org/Beagleboard:U-boot_partitioning_layout_2.0

```
uname_r=4.19.94-ti-r42
#uuid=
dtb=am335x-boneblue.dtb

###U-Boot Overlays###
###Documentation: http://elinux.org/Beagleboard:BeagleBoneBlack_Debian#U-Boot_Overlays
###Master Enable
enable_uboot_overlays=1
###pru_rproc (4.19.x-ti kernel)
uboot_overlay_pru=/lib/firmware/AM335X-PRU-RPROC-4-19-TI-00A0.dtbo
###Cape Universal Enable
enable_uboot_cape_universal=1
cmdline=coherent_pool=1M net.ifnames=0 lpj=1990656 rng_core.default_quality=100 quiet
```
