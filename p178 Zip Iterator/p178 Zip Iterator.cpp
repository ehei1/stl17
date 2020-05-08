// p178 Zip Iterator.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <vector>
#include <list>


class Zip
{
	class ZipIterator
	{
		std::vector<int>::const_iterator _i0;
		std::vector<int>::const_iterator _i1;

	public:
		ZipIterator( const std::vector<int>::const_iterator i0, const std::vector<int>::const_iterator i1 ) : 
			_i0{ i0 }, _i1{ i1 }
		{}

		ZipIterator& operator++()
		{
			++_i0;
			++_i1;

			return *this;
		}

		bool operator==( const ZipIterator& other ) const
		{
			return other._i0 == _i0 || other._i1 == _i1;
		}

		bool operator!=( const ZipIterator& other ) const
		{
			return false == operator==( other );
		}

		std::pair< int, int > operator*() const
		{
			return { *_i0, *_i1 };
		}
	};

	const std::vector<int>& _c0;
	const std::vector<int>& _c1;

public:
	explicit Zip( const std::vector<int>& c0, const std::vector<int>& c1 ) :
		_c0{ c0 }, _c1{ c1 }
	{}

	ZipIterator begin() const
	{
		return { std::cbegin( _c0 ), std::cbegin( _c1 ) };
	}

	ZipIterator end() const
	{
		return { _c0.cend(), _c1.cend() };
	}
};

int main()
{
	std::vector<int> c0{ 0,1,2,3,4 };
	std::vector<int> c1{ 2,2,2,2,2 };
	auto zip = Zip( c0, c1 );

	auto inner_product = []( auto sum, auto v ) -> int { return sum + v.first * v.second; };
	auto sum = std::accumulate( zip.begin(), zip.end(), 0, inner_product );
	std::cout << sum << std::endl;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
