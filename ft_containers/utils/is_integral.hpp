#pragma once
#include <type_traits>

namespace ft{
	template <class Tp> 	struct is_integral                     : public std::false_type {};
	template <>			 	struct is_integral<bool>               : public std::true_type {};
	template <>          	struct is_integral<char>               : public std::true_type {};
	template <>          	struct is_integral<signed char>        : public std::true_type {};
	template <>          	struct is_integral<unsigned char>      : public std::true_type {};
	template <>          	struct is_integral<wchar_t>            : public std::true_type {};
	template <>          	struct is_integral<char16_t>           : public std::true_type {};
	template <>          	struct is_integral<char32_t>           : public std::true_type {};
	template <>          	struct is_integral<short>              : public std::true_type {};
	template <>          	struct is_integral<unsigned short>     : public std::true_type {};
	template <>          	struct is_integral<int>                : public std::true_type {};
	template <>          	struct is_integral<unsigned int>       : public std::true_type {};
	template <>          	struct is_integral<long>               : public std::true_type {};
	template <>          	struct is_integral<unsigned long>      : public std::true_type {};
	template <>          	struct is_integral<long long>          : public std::true_type {};
	template <>          	struct is_integral<unsigned long long> : public std::true_type {};
}