#ifndef STRINGCOPY_H
#define STRINGCOPY_H

#include <stddef.h>

/* ALPHA version */

/**
 * @brief Copies a string from source to destination with size checks.
 *
 * This function copies a string from the source to the destination with size
 * checks to prevent buffer truncation or overflow, and ensure NUL termination.
 *
 * Internally it uses snprintf(). It does not NUL pad the destination up to the
 * src_max_size or dest_max_size.
 *
 * @param dest The destination buffer pointer.
 * @param src The source string buffer pointer.
 * @param dest_max_size The maximum size of the destination buffer including NUL terminator.
 * @param src_max_size The maximum size of the source string including NUL terminator.
 * @param dest_written A pointer to a variable to store the number of characters
 *                     actually written to the destination buffer (including the NUL terminator).
 *
 * @return 0 on success, or an error code (EFAULT, EMSGSIZE, ENOSPC, ERANGE, EOVERFLOW) on failure.
 */
int stringcopy(char * dest, const char * const src, const size_t dest_max_size, const size_t src_max_size, size_t * const dest_written);
#endif
