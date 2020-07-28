#include <iostream>
#include "header.h"
#include "cxxopts/cxxopts.h"


int main(int argc, char** argv)
{
	cxxopts::Options options("MyProgram", "One line description of MyProgram");
	options.add_options()
		("u, url", "url", cxxopts::value<std::string>())
        ("h,help", "Print usage");
  	auto result = options.parse(argc, argv);

	std::string output{};
	std::string url{};
    if (result.count("help"))
    {
      std::cout << options.help() << std::endl;
      return 0;
    }
	else
	{
		if (result.count("url"))
      		url = result["url"].as<std::string>();
	}
	
	curlStart(url, output);
	//std::cout << output <<std::endl;

	auto urlList = parseUrls(output);
	for(auto it{urlList.begin()}; it!=urlList.end(); ++it){
		std::cout << *it << " " <<std::endl;
	}
}
