#include"httplib.h"
#include<iostream>
int main() {
    httplib::Server server;

    server.Get("/", [](const httplib::Request& req, httplib::Response& res) {
        res.set_content("Hello, World!", "text/plain");
    });

    std::cout << "Server started on port 8080" << std::endl;
    server.listen("localhost", 8080);

    return 0;
}