// ----------------------------------------------------------------
// Written by:  Manuel Peinado Gallego
//              Departamento de Automática, Universidad de Alcalá
// Contact:     manupg@aut.uah.es
// Date:        October 2003
// Modified:    C gateway added by Martin Knoblauch in Oct. 2007
// You are free to use this source code in any commercial or
// non-commercial product.
// ----------------------------------------------------------------


#ifndef MPG_MEMORY_MANAGER_H
#define MPG_MEMORY_MANAGER_H

                    // Comment this line out and recompile
#define C_GATEWAY   // MemoryManager if you want a a clean
                    // C++-only (non-C) version
#ifdef new
#undef new
#endif

#ifdef delete
#undef delete
#endif

#ifdef malloc
#undef malloc
#endif

#ifdef calloc
#undef calloc
#endif

#ifdef realloc
#undef realloc
#endif

#ifdef free
#undef free
#endif

#ifdef IGNORE_FREE_NULL_FLAG
#undef IGNORE_FREE_NULL_FLAG
#endif

#ifdef IGNORE_FREE_NULL
#define IGNORE_FREE_NULL_FLAG 1
#else
#define IGNORE_FREE_NULL_FLAG 0
#endif

#ifdef __cplusplus

#include <iostream>
#include <new>

namespace MemoryManager
{
  // Public Interface
  std::ostream& setLogStream(std::ostream& stream);
  void dumpMemoryLeaks();

  namespace Private
  {
    void setContext (const char *file,
                     const char *func,
                     unsigned int line);

    enum AllocationType { NEW_ALLOCATION,
                          ARRAY_NEW_ALLOCATION,
                          NEW_NOTHROW_ALLOCATION,
                          ARRAY_NEW_NOTHROW_ALLOCATION,
                          MALLOC_ALLOCATION,
                          CALLOC_ALLOCATION,
                          REALLOC_ALLOCATION };

    enum DeallocationType { DELETE_DEALLOCATION,
                            ARRAY_DELETE_DEALLOCATION,
                            FREE_DEALLOCATION };

    void* allocate (const char *file,
                    const char *func,
                    unsigned int line,
                    AllocationType allocType,
                    size_t size);

    void* reallocate (const char *file,
                      const char *func,
                      unsigned int line,
                      size_t size,
                      void* ptr);

    void deallocate (const char *file,
                     const char *func,
                     unsigned int line,
                     DeallocationType deallocType,
                     void* ptr,
                     int ignore_free_null_flag=0);

    std::ostream& operator<< (std::ostream& os,
                              AllocationType allocType);

    std::ostream& operator<< (std::ostream& os,
                              DeallocationType deallocType);
  }
}

void * operator new (size_t size);
void * operator new[] (size_t size);
void operator delete (void * block);
void operator delete[] (void * block);
void * operator new (std::size_t, const std::nothrow_t &);
void * operator new[] (std::size_t, const std::nothrow_t &);

#define new     ( MemoryManager::Private::setContext           \
                  (__FILE__,__FUNCTION__,__LINE__), false ) ?  \
                0 : new

#define delete  ( MemoryManager::Private::setContext           \
                  (__FILE__,__FUNCTION__,__LINE__), false ) ?  \
                MemoryManager::Private::setContext("","",0) :  \
                delete

#define malloc(sz)                                             \
                MemoryManager::Private::allocate               \
                (__FILE__,__FUNCTION__,__LINE__,               \
                 MemoryManager::Private::MALLOC_ALLOCATION,    \
                 (sz))

#define	calloc(num,sz)                                         \
                MemoryManager::Private::allocate               \
                (__FILE__,__FUNCTION__,__LINE__,               \
                 MemoryManager::Private::CALLOC_ALLOCATION,    \
                 (num)*(sz))

#define realloc(ptr,sz)                                        \
                MemoryManager::Private::reallocate             \
                (__FILE__,__FUNCTION__,__LINE__,               \
                 (sz), (ptr))

#define free(ptr)                                              \
                MemoryManager::Private::deallocate             \
                (__FILE__,__FUNCTION__,__LINE__,               \
                 MemoryManager::Private::FREE_DEALLOCATION,    \
                 (ptr),IGNORE_FREE_NULL_FLAG)

#else  // __cplusplus

#include <stdio.h>
#include <stdlib.h>

#define malloc(sz)      MemoryManager_malloc                   \
                        (__FILE__,__FUNCTION__,__LINE__,       \
                         (sz))

#define	calloc(num,sz)  MemoryManager_calloc                   \
                        (__FILE__,__FUNCTION__,__LINE__,       \
                         (num)*(sz))

#define realloc(ptr,sz) MemoryManager_realloc                  \
                        (__FILE__,__FUNCTION__,__LINE__,       \
                         (sz),(ptr))

#define free(ptr)       MemoryManager_free                     \
                        (__FILE__,__FUNCTION__,__LINE__,       \
                         (ptr),IGNORE_FREE_NULL_FLAG)

#ifndef C_GATEWAY
#error Can not use this C++-only (non-C)\
       MemoryManager in plain old C
#endif // C_GATEWAY

#endif // __cplusplus

#ifdef C_GATEWAY

#ifdef __cplusplus
extern "C" {
#endif

void * MemoryManager_malloc (const char *file, const char *func,
                             unsigned int line, size_t size);

void * MemoryManager_calloc (const char *file, const char *func,
                             unsigned int line, size_t size);

void * MemoryManager_realloc (const char *file, const char *func,
                              unsigned int line, size_t size,
                              void* block);

void MemoryManager_free (const char *file, const char *func,
                         unsigned int line, void* block,
                         int ignore_free_null_flag);

void MemoryManager_DumpMemoryLeaks (void);

#ifdef __cplusplus
} // extern "C"
#endif

#endif // C_GATEWAY

#endif  // MPG_MEMORY_MANAGER_H