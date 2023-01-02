
/*platform data of the pcdev */
/**
 *
 *For this exercise, let's consider the size, serial number, and the permission as platform data.

And while registering our platform device, we have to register these information also.And let's do that.
That means, when you register your platform device you have to register the device private data also.That
what we call in this context as device platform data.

 *
 * */
struct pcdev_platform_data
{
	int size;
	int perm;
	const char *serial_number;

};

/*Permission codes */

#define RDWR 0x11
#define RDONLY 0x01
#define WRONLY 0x10
