#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define BLOCK_SIZE 100
#define MAX_BLOCKS 10

struct FileBlock
{
	char data[BLOCK_SIZE];
};

struct SequentialFile
{
	struct FileBlock blocks[MAX_BLOCKS];
	int allocatedBlocks;
	int blockAddresses[MAX_BLOCKS];
};

void initialiseFile(struct SequentialFile *);
void writeToFile(struct SequentialFile *,const char *);
void readFromFile(struct SequentialFile *);

void initialiseFile(struct SequentialFile *file)
{
	file->allocatedBlocks = 0;
	for(int i = 0; i< MAX_BLOCKS;i++)
	{
		file->blockAddresses[i] = -1;
		memset(file->blocks[i].data, 0, sizeof(file->blocks[i].data));
	}
}

void writeToFile(struct SequentialFile *file,const char *data)
{
	int dataSize = strlen(data);
	int remaining = dataSize;
	int blockIndex = file->allocatedBlocks;

	while(remaining > 0 && blockIndex < MAX_BLOCKS)
	{
		int copySize = remaining < BLOCK_SIZE ? remaining: BLOCK_SIZE;
		
		strncpy(file->blocks[blockIndex].data,data + (dataSize - remaining),copySize);
		
		file->blockAddresses[blockIndex] = blockIndex;
		remaining -= copySize;
		
		blockIndex++;
	}
	
	file->allocatedBlocks = blockIndex;
}

void readFromFile(struct SequentialFile *file)
{
	printf("\n");
	for(int i = 0; i<file->allocatedBlocks;i++)
	{
		printf("%d\n",file->blockAddresses[i]);
		printf("%s\n",file->blocks[i].data);
	}
}


void main()
{
	struct SequentialFile myFile;
	
	initialiseFile(&myFile);
	writeToFile(&myFile,"A");
	writeToFile(&myFile,"B");
	writeToFile(&myFile,"C");
	readFromFile(&myFile);
}
