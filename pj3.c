#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int *ex;

int square (int a){
	int b;
	b= a*a;
	return b;
}


int print_path(int des){
	printf("%d ",des);
	if (ex[des]<0) return 0;
	print_path(ex[des]);
	return 0;
}

int main (int argc,char* argv[]){
	
	FILE* file;
	
	int i=0;
	int g=0;
	int **map;// map is for edge
	int **map2;// map2 is adj
	int **location;// location is for coordinate
	int node;
	int edge;
	int temp1;
	int temp2;
	int *count;//counter for how many neighbor each node have
	int *distance;
	int *S;// visited list
	int *Q;
	int temp;
	int min=0;
	int counter=0;
	int round=0;
	
	//---------------initialize argv[2]-----------------//
	file = fopen(argv[2],"r"); 
	int num;
	int w;
	int *str;
	int *des;
	// get num of query
	fscanf(file,"%d ",&num);
	//printf("num: %d\n", num);
	if(file == NULL){
        printf("Fail to open argv[2]");
        return 0;
    }
    
    str = (int*) malloc (num*sizeof(int));
    des = (int*) malloc (num*sizeof(int));
    //--------------------start-----------------------
    for(w=0;w<num;w++){
    	
    fscanf(file,"%d",&str[w]);
    fscanf(file,"%d",&des[w]);
//    printf("edge1: %d\n", str[w]);
//    printf("edge1: %d\n", des[w]);
    }
	
	//---------------initialize argv[2]-----------------//
	
	//---------------initialize for argv[1]---------------
	 for(w=0;w<num;w++){
	file = fopen(argv[1],"r"); 
	
	fseek(file,0,SEEK_SET);
	
	// get how many node
	fscanf(file,"%d ",&node);
//	printf("node: %d\n", node);
	if(file == NULL){
        printf("Fail to open");
        return 0;
    }
    // get how many edge
    fscanf(file,"%d",&edge);
//    printf("edge1: %d\n", edge);
    
    //starting from initail
    
    //malloc for distance
    distance = (int*) malloc(node*sizeof(int));
    
    //malloc for ex
    ex= (int*) malloc (node*sizeof(int));
    //malloc for S
    S= (int*) malloc (node*sizeof(int));
    //malloc for Q
    Q=(int*) malloc (node*sizeof(int));
    //initial for distance 2147483647 is max for int
    
    
    for(i=0;i<node;i++){
    	distance[i] = 2147483646;
	}
	distance[str[round]] = 0;
	//initial for ex
	for(i=0;i<node;i++){
		ex[i] = (-1);//represent there is nothing
	}
//	//testing 
//	 for(i=0;i<node;i++){
//	 	printf("%d %d",	distance[i],ex[i]);
//	 }
//	//check
	//intial for S
	for(i=0;i<node;i++) S[i] = -1;// -1 represent unvisited
	for(i=0;i<node;i++) Q[i] = i;
//	 for(i=0;i<node;i++){
//	 	printf("%d %d\n",	S[i],Q[i]);
//	 } 
// check
	//---------------initialize argv[1]-----------------//
	
	

	
		//----------------------------------- get adj
		// malloc for neighbor
    map = (int**) malloc (edge*sizeof (int*));
    for (i=0;i<edge;i++){
    	map[i] = malloc(2*sizeof(int));
	}
	//malloc for map2
	map2 = (int**) malloc (node*sizeof (int*));
    for (i=0;i<node;i++){
    map2[i] = malloc(node*sizeof(int));
	}
	// malloc for location
	location = (int**) malloc (node*sizeof (int*));
	for (i=0;i<node;i++){
		location[i] = malloc(2*sizeof(int));
	}
	// malloc for map array
	map2 = (int**) malloc (node*sizeof (int*));
    for (i=0;i<node;i++){
    map2[i] = malloc(node*sizeof(int));
	}
	// malloc counter
	count = (int*) malloc (node*sizeof(int));
		//fscanf for location
	for (i=0;i<node;i++){
		fscanf(file,"%d",&location[i][0]);
		//printf("fuck my life0");
		for(g=0;g<2;g++){
			fscanf(file,"%d",&location[i][g]);
				//printf("fuck my life1");
		}
	//	printf("map%d: %d %d\n", i, location[i][0], location[i][1] );
	}
	// ---- works fine 
	//fscanf for map
	
	for (i=0;i<edge;i++){
//		printf("edge3: %d\n", edge);
//		printf("%d \n", i);
	
		fscanf(file,"%d %d",&map[i][0],&map[i][1]);
		
	
	//printf("%d",i);	
	}
//	for (i=0;i<edge;i++){  
//		printf("map%d: %d %d\n", i, map[i][0], map[i][1] );
//	}
	//check map is for edge
///---- works fine 
	
	for(i=0;i<node;i++) {
		count[i] = 0;
	}
//	for(i=0;i<node;i++) {
//		printf("\n%d",count[i]);
//	}
	//fscanf for map2
	for (i=0;i<edge;i++){
		temp1 = map[i][0];
		temp2 = map[i][1];
		
		map2[temp1][count[temp1]] = temp2;
		map2[temp2][count[temp2]] = temp1;
		map2[temp1][count[temp1]+1] = (-99);
	    map2[temp2][count[temp2]+1] = (-99);
	//	printf("%d : %d\n",temp1,map2[temp1][count[temp1]]);
	//	printf("%d : %d\n",temp2,map2[temp2][count[temp2]]);
		count[temp1]++;
		count[temp2]++;
	}
	
//	printf("test%d\n",map2[1][0]);
	
//	for (i=0;i<node;i++){
//		g=0;
//		printf("%d:",i);
//		while (map2[i][g]>-1){
//				printf(" %d,", map2[i][g]);
//				g++;
//		}
//		printf("\n");
//	}
//  works
	//----------------------------------------------------------------adj------	
	
    for(i=0;i<node;i++){
    	distance[i] = 2147483646;
	}
	distance[str[round]] = 0;
	//initial for ex
	for(i=0;i<node;i++){
		ex[i] = (-1);//represent there is nothing
	}
//	//testing 
//	 for(i=0;i<node;i++){
//	 	printf("%d %d",	distance[i],ex[i]);
//	 }
//	//check
	//intial for S
	for(i=0;i<node;i++) S[i] = -1;// -1 represent unvisited
	for(i=0;i<node;i++) Q[i] = i;
	//printf("\nhelloworld6");
	//printf("start extract min\n\n");
	//printf("\nhelloworld5");
	counter = 0;
	while(counter!=node){
	//	printf("\nhelloworld6");
		
//		for(i=0;i<node;i++){
//		printf("%d\n" ,distance[i]);
//		if(distance[i]==0) printf("fuckmylife");
//		}
		i=0;
		//extract min
		//for (i=0;i<node)
	//	printf("\nhelloworld4");
		if(counter == 0) {
			for(i=0;i<node;i++){
			
				
				if (distance[i]==0){
					break;
				
				} 
				
				
				
			}
		}
		else{
			while((distance[i])<0) {
		
		temp = distance[i];
		i++;
		}
		
		}	
		temp = distance[i];
		min = i;
		for(;i<node;i++){
		//printf("%d %d\n",distance[i],distance[i+1]);
		if ((temp > distance[i+1]) && (temp>(-2)) && (distance[i+1]>0) ) {
		temp = distance[i+1]; 
		min  = i+1;
		
		} 

		}
		//printf("2smallest%d:%d\n",min, temp);
		//Q[min] is the smallest node
		//printf("smallestnode%d\n", min);
		if(distance[min]>0)
		distance[min] = (-1) * distance[min];//means extract min
		else if(abs(distance[min] )==0) distance[min] = -1;
		
		
		
	
		//Q[min] is the smallest node
		//printf("smallestnode%d\n", min);
		
		//extract min
		
		// min & S
		S[min] = 1;//1 means visited
		// min & S				

		//----------------------------------------------------------starting to visit
		i=0;
		
		while (map2[min][i]!=(-99)){
			temp = map2[min][i];
			//printf("min distance%d\n",distance[min]);
			int z = abs(distance[min]);
			//-------relex-------------------------------------------------------------------
			if(sqrt(square((location[min][0])-(location[temp][0])) + square((location[min][1])-(location[temp][1]))) + z<abs(distance[map2[min][i]])){
//				printf("%.0lf\n",sqrt(4));
				//printf("hahahahahahahahahahahahahahahahahahahhahahaha%d\n",abs(-4));
				//printf("test%0.lf \n",sqrt(square((location[min][0])-(location[temp][0])) + square((location[min][1])-(location[temp][1]))));
				ex[map2[min][i]]= min;
				if(distance[map2[min][i]]>0)
				distance[map2[min][i]] = -(distance[min])+sqrt(square((location[min][0])-(location[temp][0])) + square((location[min][1])-(location[temp][1])));
				else 
				distance[map2[min][i]] =distance[min]-sqrt(square((location[min][0])-(location[temp][0])) + square((location[min][1])-(location[temp][1])));
			}
			//-------relex----------------------------------------------------------------------
			//printf("distance%d: %d\n",map2[min][i], distance[map2[min][i]]);
			i++;
		}
			counter++;
			
	}
	printf("\n");
	for(i=0;i<node;i++){
		distance[i] = abs(distance[i]);
		//printf("%d \n" ,distance[i]);
		}
		
	printf("\n%d\n",distance[des[round]]);
	
	print_path(des[round]);
	
	//---------------initialize argv[2]-----------------//
	round++;
	
	} 
	
	return 0;	
	}

