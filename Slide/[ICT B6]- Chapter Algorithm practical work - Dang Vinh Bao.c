
#include<stdio.h>;


//Ex1 

int binarySearch(std::vector<int> inputSeq, int find)
//inputSeq has to be a sorted asc 
sequence
{

	
int begin = 0,
 
end = inputSeq.size() - 1, 
		
 mid = inputSeq.size() / 2;


 while(begin < end){
	if (inputSeq[mid] == find)
		{
			return mid;
		}
		else if (inputSeq[mid] > find)
		{
			begin = mid + 1;
			mid = (end + begin)/2;
		}
		else
		{
			end = mid;
			mid = (end + begin)/2;
		}
	}
	
	return -1;//return -1 if it cannot found cannot found
	
}

//main
int main()
