#include <string>
#include <cstring>
#include <regex>
#include <set>
#include "curl/curl.h"


static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{ 
        //check for nullptr
        ((std::string*)userp)->append((char*)contents, size * nmemb);
        return size * nmemb;
}

void curlStart(std::string url, std::string &output )
{
    CURL* curl_{nullptr};
    CURLcode result_{};
    curl_ = curl_easy_init();
    if(!curl_) {
        std::cout << "Failed initialize Curl\n";
        return;
    }
    curl_easy_setopt(curl_, CURLOPT_URL, url.c_str());
         curl_easy_setopt(curl_, CURLOPT_WRITEFUNCTION, WriteCallback);
         curl_easy_setopt(curl_, CURLOPT_WRITEDATA, &output);
         result_ = curl_easy_perform(curl_);
        if(result_!=CURLE_OK){
            std::cout << curl_easy_strerror(result_) << std::endl;
        }`
        
    curl_easy_cleanup(curl_);
}

std::set<std::string> parseUrls(std::string input){
    std::regex url("<a href=\"(.*?)\" ", std::regex_constants::icase);
    return {std::sregex_token_iterator(input.begin(), input.end(), url, 1),  std::sregex_token_iterator{} } ;
}