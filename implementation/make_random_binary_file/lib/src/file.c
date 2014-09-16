#include "../file.h"

environment_configurations configurations;

void write_array_on_binary_file(String file_path, int * random_array, int amount_numbers){
	FILE * file_to_write = fopen(file_path,"wb+");
	
	fwrite(random_array, amount_numbers, sizeof(int), file_to_write);
	
	fclose(file_to_write);
}

void write_array_on_text_file(String file_path, int * random_array, int amount_numbers){

	String format;
	int algarisms_per_number;
	
	algarisms_per_number = count_max_algarisms(random_array, amount_numbers);
	format = generate_format_to_impress(algarisms_per_number);

	FILE * file_to_write = fopen(file_path,"w+");
	
	int actual_position;
	for(actual_position=0; actual_position< amount_numbers; actual_position++){
		if((actual_position > 0) && is_end_of_line(actual_position, algarisms_per_number))
			fprintf(file_to_write, "\n");
			
		fprintf(file_to_write, format, random_array[actual_position]);
	}
	
	fclose(file_to_write);	
}
