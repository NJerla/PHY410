#include "StudentRecordPhysics.h"
#include "StudentRecordHistory.h"
#include "StudentRecordLiterature.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <algorithm>

float calulate_average( std::vector<std::shared_ptr<StudentRecord> > const & records ) {
  float avg = 0.0;
  if ( records.size() == 0 ) {
    std::cout << "Error.... none given" << std::endl;
    return avg;
  }
  for ( std::vector< std::shared_ptr<StudentRecord> >::const_iterator it = records.begin(); it != records.end(); ++it ){
      (*it)->print(std::cout);
      avg +=(*it)->score();
  }
  
  avg /= records.size();
  return avg; 
}

bool lessthan( std::shared_ptr<StudentRecord> const &left, std::shared_ptr<StudentRecord> const & right) { return *left < *right;}

int main(int argc, char * argv[]){

  if ( argc < 2 ) {
    std::cout << "Usage: " << argv[0] << " filename.txt" << std::endl;
    return 0;
  }
  std::ifstream fin( argv[1] );


  std::vector<std::shared_ptr<StudentRecord> > records, physics, literature, history;
  bool valid = true;
  while( valid ) {
    std::string line;
    std::getline( fin, line, ',');
    if ( line == "" ) 
      break;

    if ( line == "Physics" ) {
      std::shared_ptr<StudentRecord> irecord( new StudentRecordPhysics() );
      valid = irecord->input(fin);
      if ( valid ) {
	records.push_back( irecord );
	physics.push_back( irecord );
      }
      else
	break;
    } else if ( line == "Literature" ) {
      std::shared_ptr<StudentRecord> irecord( new StudentRecordLiterature() );
      valid = irecord->input(fin);
      if ( valid ) {
	records.push_back( irecord );
	literature.push_back( irecord );
      }
      else
	break;
    } else if ( line == "History" ) {
      std::shared_ptr<StudentRecord> irecord( new StudentRecordHistory() );
      valid = irecord->input(fin);
      if ( valid ) {
	records.push_back( irecord );
	history.push_back( irecord );
      }
      else
	break;
    } else {
      std::cout << "Invalid input, ignoring" << std::endl;
      continue;
    }

  }


 std::cout << "Sorting..." << std::endl;

  std::sort( records.begin(), records.end(), lessthan );
  std::sort( physics.begin(), physics.end(), lessthan );
  std::sort( literature.begin(), literature.end(), lessthan );
  std::sort( history.begin(), history.end(), lessthan );

 std::cout << "Printing..." << std::endl;

 for ( std::vector< std::shared_ptr<StudentRecord> >::const_iterator it = records.begin(); it != records.end(); ++it ){
     (*it)->print(std::cout);
 }

  std::cout << std::endl;

  std::cout << "Tot average : " << calulate_average( records ) << std::endl;
  std::cout << "Phy average : " << calulate_average( physics ) << std::endl;
  std::cout << "Lit average : " << calulate_average( literature ) << std::endl;
  std::cout << "His average : " << calulate_average( history ) << std::endl;
}
