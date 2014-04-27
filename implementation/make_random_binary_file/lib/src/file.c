#include "../file.h"

void write_random_array_on_binary_file(String file_path, int * random_array, int amount_numbers){
	FILE * file_to_write = fopen(file_path,"wb+");
	
	fwrite(random_array, amount_numbers, sizeof(int), file_to_write);
	
	fclose(file_to_write);
}
