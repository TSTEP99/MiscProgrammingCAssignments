#include "polygon.h"

/* This function should read the number of vertices record from the file with the supplied file_name,
     allocate memory for the vertex array, and populate the array with data read from the file.
   Note that only x and y fields need to be populated by this function.
   The function should return a pointer to the populated array of vertex records and the number of read records in count.
   If the function fails to read data from the file, it should return NULL and count should be set to 0.
   INPUT:
        file_name: name of the input file located in the local directory
        count: pointer to an int for holding the number of vertices
   OUTPUTS:
        count: holds the number of vertices
   RETURN:        
        pointer to allocated and populated vertex array
        (NULL if read failure)
*/
vertex* read_polygon(char *file_name, int *count)
{
	FILE* file_ptr= fopen(file,"r");
	fscanf(file_ptr,"%d",count);
	
	
	vertex_array= (vertex*) malloc(sizeof(vertex)*(*count));
	
	int i=0;
	for(i=0;i<(*count);i++){
		int x,y;
		if(fscanf(file_ptr,"%d %d",&x,&y)==EOF){
			*count=0;
			return NULL;
		}
		vertex new_vertex={x,y,0};
		vertex_array[i]=new_vertex;
		
	}
	
	fclose(file_ptr);
    return vertex_array;
}

/* This function should calculate length of each side of the polygon as well as the polygon’s perimeter.
   The length of polygon’s side is computed as sqrt((x2-x1)^2 + (y2-y1)^2),
   This value should be stored in the length field for polygon with coordinates (x1, y1).
   Perimeter is computed by finding the sum of all side lengths of the polygon.
   This value should be computed and returned by the function.
   INPUT:
        vrtx: pointer to an array of vertices
        count: the length of the vertex array
   OUTPUTS:
        length field of each vertex calculated
   RETURN:        
        calculated perimeter
*/
float calc_perimeter(vertex* vrtx, int count)
{
	int i=0;
	int sum=0;
	int length;
	for(i=0;i<count-1;i++){
		float x1=(float)vertex[i].x,y1=(float)vertex[i].y;
		float x2=(float)vertex[i+1].x,y2=(float)vertex[i+1].y;
		length=sqrt((x2-x1)*(x2-x1)+(y2-y1)(y2-y1));
		sum+=length;
		vertex[i].length=length;
		
	}
	
	float x1=(float)vertex[count-1].x,y1=(float)vertex[count-1].y;
	float x2=(float)vertex[0].x,y2=(float)vertex[0].y;
	length=sqrt((x2-x1)*(x2-x1)+(y2-y1)(y2-y1));	
	vertex[count-1].length= length;
	sum+=length;
	
    return sum;
}

/* This function should write to file file_name the number of vertices record followed by records
     for each vertex consisting of the space-separated x, y, and length fields, followed by the perimeter.
   The function should also free memory allocated for vertex array.
   It should return 1 if the data is successfully stored in the output file, or 0 otherwise.
   INPUT:
        file_name: name of the output file
        vrtx: pointer to an array of vertices
        count: the length of the vertex array
        perimeter: the perimeter of the polygon
   OUTPUTS:
        data is written to file_name
   RETURN:        
        1 if file successfully written and vertix freed
        0 otherwise
*/
int record_polygon(char *file_name, vertex *vrtx, int count, float perimeter)
{
	FILE* file_ptr= fopen(file_name);
	if(fprintf(file_ptr,"%d\n",count)<0){
		return 0;
	}
	
	int i;
	for(i=0;i<count;i++){
			if(fprintf("%d %d %d %d\n",vrtx[i].x,vrtx[i].y,vrtx[i].length,perimeter)<0){
					return 0;
			}
	}
	
	free(vrtx)
	fclose(file_ptr);
    return 1;
}
