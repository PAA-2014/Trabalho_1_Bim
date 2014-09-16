#include "../file.h"

void write_array_on_binary_file(String file_path, int * array, int amount_numbers){

	FILE * file_to_write = fopen(file_path,"wb+");
	
	fwrite(array, amount_numbers, sizeof(int), file_to_write);
	
	fclose(file_to_write);
}

void write_array_on_text_file(String file_path, int * array, int amount_numbers){

	String format;
	int algarisms_per_number;
	
	algarisms_per_number = count_max_algarisms(array, amount_numbers);
	format = generate_format_to_impress(algarisms_per_number);

	FILE * file_to_write = fopen(file_path,"w+");
	
	int actual_position;
	for(actual_position=0; actual_position< amount_numbers; actual_position++){
		if((actual_position > 0) && is_log_end_of_line(actual_position, algarisms_per_number))
			fprintf(file_to_write, "\n");
			
		fprintf(file_to_write, format, array[actual_position]);
	}
	
	fclose(file_to_write);	
}

int * recovery_array_from_file(String file_path, int array_size){

	int * array;
	
	array = new_int_array(array_size);

	FILE * file = fopen(file_path, "rb");
	
	fread(array, array_size, sizeof(int), file);
	
	fclose(file);
	
	return array;
}

int get_amount_numbers_of_file(String file_path, int size_of_type){

	int bytes_in_file;
	bytes_in_file = get_bytes_in_file(file_path);
	
	return (bytes_in_file / size_of_type);
}

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
