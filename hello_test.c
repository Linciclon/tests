
#include <stdio.h>
#include <stdint.h> 

#define PAGE_SIZE 0x1000ULL
#define SUPERPAGE_SIZE(N) ((PAGE_SIZE) << (((2-N))*9))

#define PTE_VALID (1ULL << 0)
#define PTE_READ (1ULL << 1)
#define PTE_WRITE (1ULL << 2)
#define PTE_EXECUTE (1ULL << 3)
#define PTE_USER (1ULL << 4)
#define PTE_GLOBAL (1ULL << 5)
#define PTE_ACCESS (1ULL << 6)
#define PTE_DIRTY (1ULL << 7)

#define PTE_V PTE_VALID
#define PTE_AD (PTE_ACCESS | PTE_DIRTY)
#define PTE_U PTE_USER
#define PTE_R (PTE_READ)
#define PTE_RW (PTE_READ | PTE_WRITE)
#define PTE_X (PTE_EXECUTE)
#define PTE_RX (PTE_READ | PTE_EXECUTE)
#define PTE_RWX (PTE_READ | PTE_WRITE | PTE_EXECUTE)

uint64_t pt[512];

void pt_init(){

    uintptr_t addr = 0x0000000;
    for(int i = 0; i < 4; i++){
        pt[i] = PTE_V | PTE_AD | PTE_RWX | (addr >> 2);
        printf("pt[%d] %llx addr = %x \n", i, pt[i], addr);   
        addr +=  SUPERPAGE_SIZE(0);
        //printf("addr = %x \n", addr); 
        
        
    }
    printf("pt value: %llx \n", pt[0] ); 
    printf("pt value: %llx \n", pt ); 
    uintptr_t satp = (((uintptr_t)pt) >> 12) | (0x8ULL << 60);
    printf("pt value: %llx \n", (uintptr_t)pt ); 
    printf("pt value: %llx \n", (((uintptr_t)pt) >> 12) ); 
    printf("satp value: %llx \n", satp ); 
    printf("val: %llx\n", (0x8ULL << 60));
}


int main(){
    int a = 0x40000000;
    //typedef uint64_t pte_t;
    
    pt_init();
    
    /*
    printf("super page size: %x \n", SUPERPAGE_SIZE(0) );   
    
    printf("page size: %d \n", PAGE_SIZE);  
    
    pte_t b;
    printf("size_of: %lld \n", sizeof(b));  
    
    printf("num: %d \n", (PAGE_SIZE/sizeof(b)));    
    */
    printf("val: %x \n", a);
    a = (a>>2);
    printf("result: %x \n", a);
    /*
    printf("HELLO I'm working! \n");
*/
    return 0;

}
