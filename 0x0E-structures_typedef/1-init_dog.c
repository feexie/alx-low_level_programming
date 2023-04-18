#include <stdio.h>
#include "dog.h"
/**
 * init_dog - initialize a dog structure with the given values
 * @d: pointer to the dog structure to initialize
 * @name: pointer to a string with the dogs name
 * @age: age of the dog
 * @owner: pointer to a string with the dog's owner name
 * Return: nothing
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d != NULL)
	{
		d->name = name;
		d->age = age;
		d->owner = owner;
	}
}
