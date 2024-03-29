#include <iostream>

namespace mp
{
	template <typename T>
	class Something
	{
	public:
		Something() = default;

		// not called when S == T
		template <typename S>
		Something(const Something<S>&)
		{
			std::cout << "custom copy ctor\n";
		}

		// not called when S == T
		template <typename S>
		Something& operator=(const Something<S>&)
		{
			std::cout << "custom copy assignment operator\n";
			return *this;
		}
	};
}

int main()
{
	mp::Something<int> s1;
	mp::Something<int> s2 = s1;  // default copy ctor
	mp::Something<bool> s3 = s2; // custom copy ctor
	(void)s3;
}