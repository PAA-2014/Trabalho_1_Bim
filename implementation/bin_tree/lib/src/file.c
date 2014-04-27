#include "../file.h"

int get_bytes_in_file(String file_path){
	int bytes;

	FILE * file = fopen(file_path, "rb");
	
	seek_end(file);
	
	bytes = ftell(file);
	
	rewind(file);
	
	fclose(file);
	
	return bytes;
}

inline void seek_end(FILE * file){
	fseek(file ,0L ,SEEK_END);
}

int get_amount_numbers_of_file(String file_path, int size_of_type){
	int bytes_in_file;
	bytes_in_file = get_bytes_in_file(file_path);
	
	return (bytes_in_file / size_of_type);
}

int * recovery_array_from_file(String file_path, int array_size){
	int * array;
	
	array = (int *) malloc(array_size*sizeof(int));

	FILE * file = fopen(file_path, "rb");
	
	fread(array, array_size, sizeof(int), file);
	
	fclose(file);
	
	return array;
}
