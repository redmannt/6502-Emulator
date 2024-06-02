// Stretchy Buffers - Like vectors, but more C ;)

# pragma once

#include <assert.h>
#include <stdlib.h>

// * Utility

#define MAX(x,y)    ((x) >= (y)) ? (x) : (y)   
#define OFFSET(s,m) ((size_t)&(((s*)0)->m))

// * Structs

typedef struct Buffer_Header {
    size_t len;
    size_t cap;
    char buf[0];
} BufHdr;    

// * Defines

#define buf__hdr(b)     ((BufHdr *)((char *)b - OFFSET(BufHdr, buf)))
#define buf__fits(b,n)  (buf_len(b) + (n) <= buf_cap(b))
#define buf__fit(b,n)   (buf__fits(b,n) ? 0 : ((b) = (decltype(b))buf__grow((b), buf_len(b) + (n), sizeof(*(b)))))

#define buf_len(b)      ((b) ? buf__hdr(b)->len : 0)
#define buf_cap(b)      ((b) ? buf__hdr(b)->cap : 0)
#define buf_push(b,x)   (buf__fit(b, 1), b[buf_len(b)] = (x), buf__hdr(b)->len++)
#define buf_free(b)     ((b) ? free(buf__hdr(b)) : NULL)

// * Functions

void* buf__grow(const void *buf, 
                 size_t new_len, 
                 size_t elem_size) {
    size_t new_cap = MAX(1 + 2 * buf_cap(buf), new_len);
    size_t new_size = OFFSET(BufHdr, buf) + new_cap * elem_size;
    assert(new_len <= new_cap);
    
    BufHdr *new_hdr;
    if (buf) {
        new_hdr = (BufHdr *)realloc(buf__hdr(buf), new_size);
    } else {
        new_hdr = (BufHdr *)malloc(new_size);
        new_hdr->len = 0;
    }
    new_hdr->cap = new_cap;
    
    return new_hdr->buf; 
}
