#include <iostream>
#include <cstdio>
#include <string>

#include <ctype.h>

void print_escaped(const std::string& str)
{
	std::string printed;

	for(size_t ii=0;ii<str.size();++ii)
	{
		if(str[ii]!='\\')
		{
			printed+=str[ii];
		}
		else
		{
			std::string escape;
			++ii;

			if(ii<str.size())
			{
				escape+=str.substr(ii,1);

				while(ii+1<str.size()&&isdigit(str[ii+1])&&escape.size()<4)
				{
					escape+=str.substr(ii+1,1);
					++ii;
				}

				if(escape.size()>0)
				{
					if(isalpha(escape[0])!=0)
					{
						if(escape[0]=='r')
							printed+="\n";
						else if(escape[0]=='t')
							printed+="[TAB]";
					}
					else
					{
						if(escape=="177")
							printed+="[BSP]";
					}
				}
			}
		}
	}

	std::cout<<printed<<std::flush;
}

int main()
{
	std::string temp;
	std::string cmpr("write(3, \"");

	while(std::getline(std::cin,temp))
	{
		if(temp.size()>cmpr.size()&&temp.substr(0,cmpr.size())!=cmpr)
		{
			while(temp.size()>0&&temp[temp.size()-1]!='\"')
				temp=temp.substr(0,temp.size()-1);

			if(temp.size()>0)
				temp=temp.substr(0,temp.size()-1);

			while(temp.size()>0&&temp[0]!='\"')
				temp=temp.substr(1,temp.size()-1);

			if(temp.size()>0)
				temp=temp.substr(1,temp.size()-1);

			print_escaped(temp);
		}
	}

	return 0;
}