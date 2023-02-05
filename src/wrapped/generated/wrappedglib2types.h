/*******************************************************************
 * File automatically generated by rebuild_wrappers.py (v2.1.0.16) *
 *******************************************************************/
#ifndef __wrappedglib2TYPES_H_
#define __wrappedglib2TYPES_H_

#ifndef LIBNAME
#error You should only #include this file inside a wrapped*.c file
#endif
#ifndef ADDED_FUNCTIONS
#define ADDED_FUNCTIONS() 
#endif

typedef void (*vFp_t)(void*);
typedef void* (*pFp_t)(void*);
typedef void (*vFpp_t)(void*, void*);
typedef void (*vFpV_t)(void*, ...);
typedef int64_t (*iFpp_t)(void*, void*);
typedef int64_t (*iFpV_t)(void*, ...);
typedef int64_t (*iFpA_t)(void*, va_list);
typedef uint64_t (*uFpp_t)(void*, void*);
typedef uintptr_t (*LFpA_t)(void*, va_list);
typedef void* (*pFup_t)(uint64_t, void*);
typedef void* (*pFpu_t)(void*, uint64_t);
typedef void* (*pFpp_t)(void*, void*);
typedef void* (*pFpV_t)(void*, ...);
typedef void* (*pFpA_t)(void*, va_list);
typedef void (*vFppp_t)(void*, void*, void*);
typedef void (*vFppV_t)(void*, void*, ...);
typedef void (*vFppA_t)(void*, void*, va_list);
typedef int64_t (*iFppV_t)(void*, void*, ...);
typedef int64_t (*iFppA_t)(void*, void*, va_list);
typedef uint64_t (*uFipp_t)(int64_t, void*, void*);
typedef uint64_t (*uFupp_t)(uint64_t, void*, void*);
typedef uint64_t (*uFppp_t)(void*, void*, void*);
typedef void* (*pFppp_t)(void*, void*, void*);
typedef void* (*pFppV_t)(void*, void*, ...);
typedef void (*vFpipV_t)(void*, int64_t, void*, ...);
typedef void (*vFpipA_t)(void*, int64_t, void*, va_list);
typedef void (*vFpupp_t)(void*, uint64_t, void*, void*);
typedef void (*vFpppp_t)(void*, void*, void*, void*);
typedef int64_t (*iFpLpV_t)(void*, uintptr_t, void*, ...);
typedef int64_t (*iFpLpA_t)(void*, uintptr_t, void*, va_list);
typedef uint64_t (*uFippp_t)(int64_t, void*, void*, void*);
typedef uint64_t (*uFpipp_t)(void*, int64_t, void*, void*);
typedef void* (*pFpipp_t)(void*, int64_t, void*, void*);
typedef void* (*pFpipV_t)(void*, int64_t, void*, ...);
typedef void* (*pFpipA_t)(void*, int64_t, void*, va_list);
typedef void* (*pFpupp_t)(void*, uint64_t, void*, void*);
typedef void* (*pFppip_t)(void*, void*, int64_t, void*);
typedef void* (*pFpppp_t)(void*, void*, void*, void*);
typedef void (*vFpiLpp_t)(void*, int64_t, uintptr_t, void*, void*);
typedef void (*vFppipV_t)(void*, void*, int64_t, void*, ...);
typedef uint64_t (*uFiippp_t)(int64_t, int64_t, void*, void*, void*);
typedef uint64_t (*uFiuppp_t)(int64_t, uint64_t, void*, void*, void*);
typedef void* (*pFppppp_t)(void*, void*, void*, void*, void*);
typedef void (*vFpiiipp_t)(void*, int64_t, int64_t, int64_t, void*, void*);
typedef int64_t (*iFpupppp_t)(void*, uint64_t, void*, void*, void*, void*);
typedef uint64_t (*uFpiippp_t)(void*, int64_t, int64_t, void*, void*, void*);
typedef void* (*pFppuipp_t)(void*, void*, uint64_t, int64_t, void*, void*);
typedef void* (*pFppLiiip_t)(void*, void*, uintptr_t, int64_t, int64_t, int64_t, void*);
typedef int64_t (*iFpppipppp_t)(void*, void*, void*, int64_t, void*, void*, void*, void*);
typedef int64_t (*iFpppipppppp_t)(void*, void*, void*, int64_t, void*, void*, void*, void*, void*, void*);
typedef int64_t (*iFpppippppppp_t)(void*, void*, void*, int64_t, void*, void*, void*, void*, void*, void*, void*);

#define SUPER() ADDED_FUNCTIONS() \
	GO(g_atexit, vFp_t) \
	GO(g_completion_new, pFp_t) \
	GO(g_main_context_get_poll_func, pFp_t) \
	GO(g_private_new, pFp_t) \
	GO(g_ptr_array_new_with_free_func, pFp_t) \
	GO(g_set_print_handler, pFp_t) \
	GO(g_set_printerr_handler, pFp_t) \
	GO(g_array_set_clear_func, vFpp_t) \
	GO(g_array_sort, vFpp_t) \
	GO(g_completion_set_compare, vFpp_t) \
	GO(g_list_free_full, vFpp_t) \
	GO(g_main_context_set_poll_func, vFpp_t) \
	GO(g_ptr_array_set_free_func, vFpp_t) \
	GO(g_ptr_array_sort, vFpp_t) \
	GO(g_slist_free_full, vFpp_t) \
	GO(g_source_set_funcs, vFpp_t) \
	GO(g_thread_foreach, vFpp_t) \
	GO(g_print, vFpV_t) \
	GO(g_printerr, vFpV_t) \
	GO(g_source_remove_by_funcs_user_data, iFpp_t) \
	GO(g_printf, iFpV_t) \
	GO(g_vprintf, iFpA_t) \
	GO(g_idle_add, uFpp_t) \
	GO(g_printf_string_upper_bound, LFpA_t) \
	GO(g_ptr_array_new_full, pFup_t) \
	GO(g_source_new, pFpu_t) \
	GO(g_hash_table_new, pFpp_t) \
	GO(g_list_sort, pFpp_t) \
	GO(g_log_set_default_handler, pFpp_t) \
	GO(g_slist_sort, pFpp_t) \
	GO(g_strjoinv, pFpp_t) \
	GO(g_variant_new_parsed_va, pFpp_t) \
	GO(g_build_filename, pFpV_t) \
	GO(g_markup_printf_escaped, pFpV_t) \
	GO(g_strconcat, pFpV_t) \
	GO(g_strdup_printf, pFpV_t) \
	GO(g_strjoin, pFpV_t) \
	GO(g_variant_new, pFpV_t) \
	GO(g_markup_vprintf_escaped, pFpA_t) \
	GO(g_strdup_vprintf, pFpA_t) \
	GO(g_array_sort_with_data, vFppp_t) \
	GO(g_hash_table_foreach, vFppp_t) \
	GO(g_list_foreach, vFppp_t) \
	GO(g_option_context_add_main_entries, vFppp_t) \
	GO(g_ptr_array_foreach, vFppp_t) \
	GO(g_ptr_array_sort_with_data, vFppp_t) \
	GO(g_static_private_set, vFppp_t) \
	GO(g_string_append_printf, vFppV_t) \
	GO(g_string_printf, vFppV_t) \
	GO(g_variant_get, vFppV_t) \
	GO(g_string_append_vprintf, vFppA_t) \
	GO(g_string_vprintf, vFppA_t) \
	GO(g_fprintf, iFppV_t) \
	GO(g_sprintf, iFppV_t) \
	GO(g_vasprintf, iFppA_t) \
	GO(g_vfprintf, iFppA_t) \
	GO(g_vsprintf, iFppA_t) \
	GO(g_child_watch_add, uFipp_t) \
	GO(g_timeout_add, uFupp_t) \
	GO(g_timeout_add_seconds, uFupp_t) \
	GO(g_hash_table_foreach_remove, uFppp_t) \
	GO(g_hash_table_foreach_steal, uFppp_t) \
	GO(g_hash_table_find, pFppp_t) \
	GO(g_list_find_custom, pFppp_t) \
	GO(g_list_insert_sorted, pFppp_t) \
	GO(g_list_sort_with_data, pFppp_t) \
	GO(g_node_copy_deep, pFppp_t) \
	GO(g_queue_find_custom, pFppp_t) \
	GO(g_slist_find_custom, pFppp_t) \
	GO(g_slist_foreach, pFppp_t) \
	GO(g_slist_insert_sorted, pFppp_t) \
	GO(g_slist_sort_with_data, pFppp_t) \
	GO(g_variant_new_va, pFppp_t) \
	GO(g_build_path, pFppV_t) \
	GO(g_log, vFpipV_t) \
	GO(g_logv, vFpipA_t) \
	GO(g_datalist_id_set_data_full, vFpupp_t) \
	GO(g_source_set_callback, vFpppp_t) \
	GO(g_snprintf, iFpLpV_t) \
	GO(g_vsnprintf, iFpLpA_t) \
	GO(g_idle_add_full, uFippp_t) \
	GO(g_io_add_watch, uFpipp_t) \
	GO(g_log_set_handler, uFpipp_t) \
	GO(g_markup_parse_context_new, pFpipp_t) \
	GO(g_error_new, pFpipV_t) \
	GO(g_error_new_valist, pFpipA_t) \
	GO(g_datalist_id_dup_data, pFpupp_t) \
	GO(g_thread_create, pFppip_t) \
	GO(g_hash_table_new_full, pFpppp_t) \
	GO(g_slist_insert_sorted_with_data, pFpppp_t) \
	GO(g_thread_try_new, pFpppp_t) \
	GO(g_qsort_with_data, vFpiLpp_t) \
	GO(g_set_error, vFppipV_t) \
	GO(g_child_watch_add_full, uFiippp_t) \
	GO(g_timeout_add_full, uFiuppp_t) \
	GO(g_timeout_add_seconds_full, uFiuppp_t) \
	GO(g_option_group_new, pFppppp_t) \
	GO(g_node_traverse, vFpiiipp_t) \
	GO(g_datalist_id_replace_data, iFpupppp_t) \
	GO(g_io_add_watch_full, uFpiippp_t) \
	GO(g_variant_new_from_data, pFppuipp_t) \
	GO(g_thread_create_full, pFppLiiip_t) \
	GO(g_spawn_async, iFpppipppp_t) \
	GO(g_spawn_sync, iFpppipppppp_t) \
	GO(g_spawn_async_with_pipes, iFpppippppppp_t)

#endif // __wrappedglib2TYPES_H_
