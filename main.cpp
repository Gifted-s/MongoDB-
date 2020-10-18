#include <iostream>

using namespace std;
class MongoClient {
  static int version;
  private:
      string url;
      string data[120];
      string collection;
      string dbName;
  public:


      void connect(){
      cout << "Database connetcted"<<endl;
      showDBDetails();
      }
      string setDbName(string adbName){
      dbName= adbName;
      }
      string showDBDetails(){
        cout <<"Database Name: "<< dbName<<endl;
        cout <<"Collection: "<< collection<< endl;
        cout <<"Connection URL: "<< url<< endl;
      }
      string insertOne(string whatToInsert){
        cout<<"Hello";
        string bookName;
        string bookAuthor;
        string pages;
        cout<< "Enter book name"<<endl;
        cin>> bookName;
        cout<< "Enter book author"<< endl;
        cin>> bookAuthor;
        cout<< "Enter number of pages"<< endl;
        cin>> pages;
        whatToInsert += bookName;
        for(int i=0; i<120; i++){
          if(data[i] == ""){
            data[i] = whatToInsert;
            break;
          }
        }
        return *data;
      }
      string findOne(string query){
          string result;
          for(int i=0; i<120; i++){
          int index = data[i].find(query, 0);
          if(data[index] != ""){
            result= data[index];
            break;
          }
        }

        return result;
      }
      string findAll(){
        return *data;
      }
      string deleteOne(string whatToDelete){
        for(int i=0; i<120; i++){
          int index = data[i].find(whatToDelete, 0);
          if(data[index] != ""){
            data[index] = "";
            break;
          }
        }

        return *data;
      }
      string updateOne(){

      }
      string updateMany(){

      }
      void setUrl(string aurl){
        url = aurl;
      }
      void setCollectionName(string aColl){
        collection = aColl;
      }

};

int main()
{    cout<<"hello";
     MongoClient client;
     client.setUrl("mongodb://127:0.0.1:27101");
     client.setDbName("bookDB");
     client.setCollectionName("books");
     client.connect();
    return 0;
}
