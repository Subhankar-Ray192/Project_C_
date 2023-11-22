#include<stdio.h>
#include<stdlib.h>

#define MAX_MEM 250
#define SMALL_MEM 10
#define MEDIUM_MEM 20
#define LARGE_MEM 50

typedef struct memory_partition
{
	int size;
	int str_add;
	int h_size;
}m_part;

typedef struct memory_block
{
	int tot_mem;
	int partition_stat;
	m_part obj[3];
	struct memory_block *nxt_block;
}m_block;

void memory_allocation(m_block *,int,int);
void memory_parition_check(int,m_block *);
int memory_address_collision(int,int,m_block *);
void memory_show(m_block *);
void memory_gc(m_block *);


void memory_gc(m_block *head)
{
	m_block *copy_block =head;
	while(copy_block->nxt_block!=NULL)
	{
		m_block *temporary_block=copy_block;
		copy_block=copy_block->nxt_block;
		free(temporary_block);
	}
	free(copy_block);
}

int memory_address_collision(int start,int stat,m_block *head)
{
	//printf("Hello-2");
	int n_collision_counter = 0;
	int block_counter = 0;
	
	m_block * copy_block=head->nxt_block;
	int tot_file_mem = start + head->obj[stat].size;

	while(copy_block->nxt_block!=NULL)
	{
		block_counter++;
		int tot_part_mem = copy_block->obj[copy_block->partition_stat].str_add + copy_block->obj[copy_block->partition_stat].size;
		
		if((tot_part_mem < start)||(tot_file_mem < copy_block->obj[copy_block->partition_stat].str_add))
		{
			n_collision_counter++;
		}
		
		copy_block=copy_block->nxt_block;
	}

	if(block_counter==n_collision_counter)
	{
		//printf("TTT");
		return 1;
	}
	return 0;
}

void memory_partition_check(int r_size, m_block *ptr)
{
	//printf("Hello-1");
	if(r_size<=SMALL_MEM)
	{
		//printf("YYY");
		ptr->tot_mem=MAX_MEM - SMALL_MEM;
		ptr->partition_stat=0;
		ptr->obj[0].h_size = SMALL_MEM - r_size;
		ptr->obj[0].size = SMALL_MEM;
	}
	else if(r_size<=MEDIUM_MEM)
	{
		ptr->tot_mem=MAX_MEM - MEDIUM_MEM;
		ptr->partition_stat=1;
		ptr->obj[1].h_size = MEDIUM_MEM - r_size;
		ptr->obj[1].size = MEDIUM_MEM;
	}
	else if(r_size<=LARGE_MEM)
	{
		ptr->tot_mem=MAX_MEM - LARGE_MEM;
		ptr->partition_stat=2;
		ptr->obj[2].h_size = LARGE_MEM - r_size;
		ptr->obj[2].size = LARGE_MEM;
	}
	else if(r_size>LARGE_MEM)
	{
		printf("\nOVERLOAD");
		ptr->tot_mem=MAX_MEM - LARGE_MEM;
		ptr->partition_stat=4;
	}
	else
	{
		printf("\nERROR");
		ptr->tot_mem=MAX_MEM - LARGE_MEM;
		ptr->partition_stat=-1;
	}
}


void memory_allocation(m_block *head,int start,int r_size)
{
	//printf("Hello");
	if(head->nxt_block==NULL)
	{
		head->tot_mem=MAX_MEM;
		head->obj[0].size=SMALL_MEM;
		head->obj[1].size=MEDIUM_MEM;
		head->obj[2].size=LARGE_MEM;
		
		m_block *tail = (m_block *)malloc(sizeof(m_block));
		
		tail->tot_mem=MAX_MEM;
		tail->obj[0].size=SMALL_MEM;
		tail->obj[1].size=MEDIUM_MEM;
		tail->obj[2].size=LARGE_MEM;
		tail->nxt_block=NULL;
	
		head->nxt_block=tail;
	}
	
	m_block *ptr = (m_block *)malloc(sizeof(m_block));
	memory_partition_check(r_size,ptr);

	if(memory_address_collision(start,ptr->partition_stat,head))
	{
		//printf("Hello-4");
		ptr->obj[ptr->partition_stat].str_add = start;
	
		ptr->nxt_block=head->nxt_block;
		head->nxt_block=ptr;
	}
}

void memory_show(m_block *head)
{
	m_block *copy_block=head->nxt_block;
	printf("\nMemory-List:");
	while(copy_block->nxt_block!=NULL)
	{
		//printf("Hello-5");
		printf("(%d,%d,%d)",copy_block->obj[copy_block->partition_stat].size,copy_block->obj[copy_block->partition_stat].str_add,copy_block->obj[copy_block->partition_stat].h_size);
		copy_block=copy_block->nxt_block;
	}
}

void main()
{
	m_block *ptr = (m_block *)malloc(sizeof(m_block));
	
	memory_allocation(ptr,30,5);
	memory_show(ptr);
	
	memory_gc(ptr);
}



