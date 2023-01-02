#include<linux/module.h>
#include<linux/platform_device.h>

#include "platform.h" //iske andar mera platofrma devices struct pcdev_platform_data   ka private data hai size,permision etc 

#undef pr_fmt
#define pr_fmt(fmt) "%s : " fmt,__func__

void pcdev_release(struct device *dev)
{
	pr_info("Device released \n");
}


/*1. create n platform data */
/**
 *4 Platform devices ke liye 4 platform data create kar rha hoon 
 *struct pcdev_platform_data  structre me mera plataromdeivce private data hai ok 
 * */
struct pcdev_platform_data  pcdev_pdata[] = {
	[0] = {.size = 512, .perm = RDWR,   .serial_number = "PCDEVABC1111"},//oth array elemnt 
	[1] = {.size = 1024,.perm = RDWR,   .serial_number = "PCDEVXYZ2222"},//1st array elemnt 
	[2] = {.size = 128, .perm = RDONLY, .serial_number = "PCDEVXYZ3333"},//2nd array elemnt and so on 
	[3] = {.size = 32,  .perm = WRONLY, .serial_number = "PCDEVXYZ4444"}
};

/*2. create n platform devices */ 
/***
 *
 *struct platform_device {
	const char	*name; //name of platform device 
	u32		id;//platform devices ek group hoga toh ye id index jese  use hoga ..id =0 or id=1 aise ok 
	struct device	dev;
	u32		num_resources;
	struct resource	*resource;
};

ye structure ka member ko fill kar rha hoon 

 *
 *
 * ***/
struct platform_device platform_pcdev_1 = {
	.name = "kamal-A1x",
	.id = 0,
	.dev = {
		.platform_data = &pcdev_pdata[0],
		.release = pcdev_release
	}
};


struct platform_device platform_pcdev_2 = {
	.name = "kamal-B1x",
	.id = 1,
	.dev = {
		.platform_data = &pcdev_pdata[1],
		.release = pcdev_release
	}
};


struct platform_device platform_pcdev_3 = {
	.name = "kamal-C1x",
	.id = 2,
	.dev = {
		.platform_data = &pcdev_pdata[2],
		.release = pcdev_release
	}
};


struct platform_device platform_pcdev_4 = {
	.name = "kamal-D1x",
	.id = 3,
	.dev = {
		.platform_data = &pcdev_pdata[3],
		.release = pcdev_release
	}
};


struct platform_device *platform_pcdevs[] = 
{
	&platform_pcdev_1,
	&platform_pcdev_2,
	&platform_pcdev_3,
	&platform_pcdev_4
};

static int __init pcdev_platform_init(void)
{
	/* register n platform devices */
//jab v insmod karunga ye platkform devices ko reogister karunga ok ..
//
	//platform_device_register(&platform_pcdev_1);
	//platform_device_register(&platform_pcdev_2);
	
	platform_add_devices(platform_pcdevs,ARRAY_SIZE(platform_pcdevs) );

	pr_info("Device setup module loaded \n");

	return 0;
}


static void __exit pcdev_platform_exit(void)
{

	//jab v mein rmmod karke module ko remove karunga toh mein platform devices ko remove karunga ok ..
	platform_device_unregister(&platform_pcdev_1);
	platform_device_unregister(&platform_pcdev_2);
	platform_device_unregister(&platform_pcdev_3);
	platform_device_unregister(&platform_pcdev_4);
	pr_info("Device setup module unloaded \n");


}

module_init(pcdev_platform_init);
module_exit(pcdev_platform_exit);


MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Module which registers n platform devices ");
MODULE_AUTHOR("Kiran Nayak");


