#include <iostream>
using namespace std;
class solution
{
	public:
	int reverseTheNumber(int temp)
{
	int ans = 0;
	while (temp > 0) {
		int rem = temp % 10;
		ans = ans * 10 + rem;
		temp = temp / 10;
	}
	return ans;
}/*you are required to complete this method*/
    int convertFive(int num)
    {
    //Your code here
    // if num is 0 return 5
	if (num == 0)
		{return 5;}

	// change it if needed
	else {
		int temp = 0;

		while (num > 0) {
			int digit = num % 10;
			//if digit is 0, make it 5
			if (digit == 0)
				{digit = 5;}

			temp = temp * 10 + digit;
			num = num / 10;
		}
		return reverseTheNumber(temp);
    }
}};

int main()
{
	int n;
	cin>>n;
	solution obj;
	cout<<obj.convertFive(n)<<endl;
}