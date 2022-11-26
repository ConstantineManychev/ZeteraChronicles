#ifndef __DATA_TYPES_H__
#define __DATA_TYPES_H__

#define UNDEFINED_STR "UNDEFINED"
#define NONE_STR "NONE"

struct sSize
{
	int width;
	int height;
};

struct sVec
{
	int x;
	int y;
};

struct sSize3
{
	int width;
	int height;
	int depth;
};

struct sVec3
{
	int x;
	int y;
	int z;
};

#endif
