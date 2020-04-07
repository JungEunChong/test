#include "lib_members.h"

T_record * lib_members[MAX_MEMBERS];
int count = 0;

int m_is_available()
{
	for (int i = 0 ; i < MAX_MEMBERS; i++)
	{
		if (lib_members[i] == 0x0)
			return 1;
	}

	return 0;
}

int m_first_available()
{
	 for(int i = 0; i < MAX_MEMBERS ; i++)
	 {
		 if(lib_members[i] == 0x0)
			 return i;			   
	 }
			  
	 return -1;
}


int m_count()
{
	return count;
}



void m_create(char *n, char *p, char *b, char *c)
{
	int index = m_first_available();
	lib_members[index] = (T_record * )malloc(sizeof(T_record));
	T_record *ptr = lib_members[index];

	strcpy(ptr->name, n);
	strcpy(ptr->phone, p);
	strcpy(ptr->birthyear, b);
	strcpy(ptr->city, c);
	
	number_create(ptr);
	count += 1;

}

char* m_to_string(T_record* p)
{
	static char str[80];
	sprintf(str, "[%s] %s / %s / %s", p->birthyear, p->name, p->phone, p->city);
	return str;
}

T_record * m_search_by_name(char *n)
{
	for (int i = 0; i < count ; i++)
	{
		if(lib_members[i] != 0x0 && strcmp(lib_members[i]->name, n) == 0)
			return lib_members[i];
	}
	
	return 0x0;
}

void number_create(T_record * p)
{
	char *str  = malloc(sizeof(char) * 20);

	strcpy(str , p->birthyear);
	strcat(str, p->phone);
	
	strcpy(p->number, str);

	free(str);
#ifdef DEBUG
	printf("\n*Library number is made*\n");
#endif
}

void m_get_all(T_record * a[])
{
	int i;
	for (i = 0; i < MAX_MEMBERS; i++)
	{
		a[i] = lib_members[i];
	}
}

void m_get_all2(T_record* a[])
{
	int i;
	for(i=0; i<MAX_MEMBERS; i++)
	{
		a[i]=lib_members[i];
	}
}


char* m_getname(T_record* p)
{
	return p->name;
}

char* m_getphone(T_record* p)
{
	return p->phone;
}

char* m_getbirthyear(T_record* p)
{
	return p->birthyear;
}

char* m_getcity(T_record* p)
{
	return p->city;
}

char* m_getnumber(T_record* p)
{
	return p->number;
}

void m_init()
{
	// 모든 레코드 제거    
	int i;
	for(i=0; i<MAX_MEMBERS; i++)
	{
		if(lib_members[i]!=NULL)
		{
			free(lib_members[i]);
		}
		lib_members[i] = NULL;
	}
	count = 0;

}

char* m_to_string_save(T_record* p)
{
	static char str[80];
	sprintf(str, "%s %s %s %s", p->name, p->phone, p->birthyear, p->city);
	return str;
}
