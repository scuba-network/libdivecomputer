/*
 * libdivecomputer
 *
 * Copyright (C) 2026 DSCNT LTD
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301 USA
 */

/*
 * Added by DSCNT on 30 October 2026 (scuba-network/app#1122).
 */

#ifndef DC_SHEARWATER_PETREL_H
#define DC_SHEARWATER_PETREL_H

#include <libdivecomputer/common.h>
#include <libdivecomputer/device.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/*
 * Asked once for each dive in the computer's dive list (its manifest), after
 * the list is read and before any dive's profile is downloaded. fingerprint is
 * the fingerprint dc_device_foreach() reports for that dive (4 bytes: the
 * dive's start, in seconds since 1970 on the computer's own clock, big
 * endian). Return nonzero to leave the dive out: its profile is not
 * downloaded, the dive callback is not called for it, and it is not counted
 * in the progress.
 */
typedef int (*shearwater_petrel_skip_callback_t) (const unsigned char fingerprint[], unsigned int size, void *userdata);

/*
 * Sets the callback for a Shearwater Petrel family device, or clears it with
 * NULL. Call it before dc_device_foreach(). Returns DC_STATUS_INVALIDARGS for
 * any other device.
 */
dc_status_t
shearwater_petrel_device_set_skip (dc_device_t *device, shearwater_petrel_skip_callback_t callback, void *userdata);

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* DC_SHEARWATER_PETREL_H */
