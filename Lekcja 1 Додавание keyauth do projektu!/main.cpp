#include <windows.h>
#include "string"
#include <iostream>	
#include "auth.hpp" // Need to use keyauth in your project
#include "json.hpp" // Need to use keyauth in your project
#include "skStr.h" // Need to use keyauth in your project
#include "utils.hpp" // Need to use keyauth in your project

using namespace KeyAuth;

std::string name = skCrypt("123").decrypt(); // KEY AUTH APP NAME
std::string ownerid = skCrypt("123").decrypt(); // OWNER ID FROM KEYAUTH
std::string version = skCrypt("1.0").decrypt(); // DO NOT CHANGE ! ! !
std::string url = skCrypt("https://keyauth.win/api/1.3/").decrypt(); // DO NOT CHANGE ! ! !
std::string path = skCrypt("").decrypt(); // DO NOT CHANGE ! ! !

api Auth(name, ownerid, version, url, path); // Auth (main keyauth function used to e.g validate license)

int main() {
	std::string username; // DO NOT CHANGE
	std::cin >> username; // INPUT USERNAME FROM KEYAUTH
	std::string passowrd; // DO NOT CHANGE
	std::cin >> passowrd; // INPUT PASSWORD FROM KEYAUTH
	Auth.init(); // INIT KEYAUTH TO PROJECT
	Auth.login(username, passowrd); // VALIDATE USERNAME AND PASSWORD FROM KEYAUTH (E.G USER HAS LICENSE)

	if (Auth.response.success) { // If user has
		std::cout << "Logged in"; // Information user logged in
	}
	else { 
		std::cout << "Invalid credentials"; // Info : invalid password / username / license expired / invalid hwid
	}
}