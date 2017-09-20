float prod_esc (int dim, float* x, float* y){
    float prod = 0.f;
    int i;
    
    for (i = 0; i < dim; i++){
        prod += x[i]* y[i];
    }
    
    return prod;
}
