void sortby_sales(struct book books[]){
    int count = sizeof(books)/sizeof(books[0]);
    for(i = 0; i < count -1; i++){
        for(j = 0; j < count -1; j++){
            if(books[j].sales > books[j+1].sales){
                temp = books[j];
                books[j] = books[j+1];
                books[j+1] = temp;
            }
        }
    }
}