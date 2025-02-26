#include <iostream>
#include <string>
#include <>cpprest/http_client.h>
#include <cpprest/filestream.h>

using namespace std;
using namespace web;
using namespace web :: http;
using namespace web :: http :: client;

int main()
{
	cout << "\t+-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o+" <<endl;
	cout << "\t\t+My Weather App" <<endl;
	cout << "\t+-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o+" <<endl;
	cout << "\tEnter City Name: ";
	string city;
	getline (cin, city);
	
	http_client client(U("ap link will be pasted here"));
	uri_builder builder(U("/weather"));
	builder.append_query(U("q"), utility::conversions::to_string_t(city));
	builder.append_query(U("appid"), U("paste app id of apa"));
	http_request request(method::GET);
	request.set_request_url(builder.to_string());
	 
	client request(request).then([](http_response response){
		return  response.extract_jason();	
	}
	).then([](web::jason::value body){
		cout << "\tTemperature: " << body[U("main")][U("temp")].as_double() << "K" <<endl;
		cout << "\tHumidity: " <<body[U("main")][U("humidity")].as_double() << "%" <<endl;
		cout << "\tWeather: " <<utility::conversion::to_utf8string(body[U("weather")][0][("main")]).as_string());
	}
	).wait();
	
	return 0; 
	
	
	
	

}

