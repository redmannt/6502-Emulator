// Stretchy Buffers - Like vectors, but more C ;)

# pragma once

#include <assert.h>
#include <stdlib.h>

// * Utility

#define max(x,y)        ((x) >= (y)) ? (x) : (y)   
#define offset(s,m)     ((s_t)&(((s*)0)->m))

#define easy_malloc(x)  (decltype(x))malloc(sizeof(decltype(*x))); assert(x)
#define easy_free(x)     assert(x); (free(x), x = NULL)    

// * Structs

typedef struct Stretchy_Buffer_Header {
    s_t len;
    s_t cap;
    char buf[0];
} BufHdr;    

#define buf__hdr(b) ((BufHdr *)((char *)b - offset(BufHdr, buf)))

#define buf_len(b)  ((b) ? buf__hdr(b)->len : 0)
#define buf_cap(b)  ((b) ? buf__hdr(b)->cap : 0)

void * 
buf__grow(const void *buf, 
          s_t new_len, 
          s_t elem_size) {
    s_t new_cap  = max(1 + 2 * buf_cap(buf), new_len);
    s_t new_size = offset(BufHdr, buf) + new_cap * elem_size;
    assert(new_len <= new_cap);
    
    BufHdr *new_hdr;
    if (buf) {
        new_hdr = (BufHdr *)realloc(buf__hdr(buf), new_size);
        assert(new_hdr);
    } else {
        new_hdr = (BufHdr *)malloc(new_size);
        assert(new_hdr);
        new_hdr->len = 0;
    }
    new_hdr->cap = new_cap;
    
    return new_hdr->buf; 
}

#define buf__fits(b,n) (buf_len(b) + (n) <= buf_cap(b))
#define buf__fit(b,n)  (buf__fits(b,n) ? \
                       NULL : \
                       ((b) = (decltype(b))buf__grow((b), buf_len(b) + (n), sizeof(*(b)))))

#define buf_push(b,x)  (buf__fit(b,1), (b)[buf_len(b)] = (x), buf__hdr(b)->len++)
#define buf_free(b)    ((b) ? (free(buf__hdr(b)), (b) = NULL) : NULL)
