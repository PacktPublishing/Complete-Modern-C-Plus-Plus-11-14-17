
#include <iostream>
#include <optional>
#include <expected>
std::optional<const char*> GetErrorStringOp(int errorNo) {
	switch (errorNo) {
	case 0:
		return "Invalid input";
	case 1:
		return "Connection not established yet\n";
	default:
		return std::nullopt;
	}
}
std::expected<const char*, const char *> GetErrorStringEx(int errorNo) {
	switch (errorNo) {
	case 0:
		return "Invalid input";
	case 1:
		return "Connection not established yet\n";
	default:
		//return std::expected<const char*, const char*>{std::unexpect, "Invalid error number"};
		return std::unexpected("Invalid error number");
	}
}
enum struct FindUserError {
	UserNotFound,
	ContractorHasNoId
};
std::expected<int, FindUserError> FindUserId(std::string_view name) {
	using enum FindUserError ;
	if (name == "Umar") {
		return 101;
	} 
	if (name == "Joe") {
		return 201;
	} 
	if (name == "Bob") {
		return 301;
	}
	if (name == "Alice") {
		//Alice is a contractor, and does not have an id
		return std::unexpected(ContractorHasNoId);
	}
	//User not found
	return std::unexpected(UserNotFound);
}
int main() {
	try {
		//auto exp = GetErrorStringEx(4) ;
		//exp.value();
		//if (exp) {
		//	std::cout << *exp /*exp.value()*/ << '\n' ;
		//}else {
		//	std::cout << exp.error() << '\n' ;
		//}
		//return 0 ;

		auto result = FindUserId("Alice") ;
		if (result) {
			std::cout << *result << '\n' ;
		}else {
			switch (result.error()) {
			case FindUserError::ContractorHasNoId:
				std::cout << "User exists, but is a contractor!\n";
				break ;
			case FindUserError::UserNotFound:
				std::cout << "User does not exist!\n" ;
				break ;
			}
		}
	} catch (std::exception& ex) {
		std::cout << "Exception:" << ex.what() << std::endl;
	}

}