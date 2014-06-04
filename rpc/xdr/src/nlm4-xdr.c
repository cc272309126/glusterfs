/*
  Copyright (c) 2007-2012 Red Hat, Inc. <http://www.redhat.com>
  This file is part of GlusterFS.

  This file is licensed to you under your choice of the GNU Lesser
  General Public License, version 3 or any later version (LGPLv3 or
  later), or the GNU General Public License, version 2 (GPLv2), in all
  cases as published by the Free Software Foundation.
*/

/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "nlm4-xdr.h"

bool_t
xdr_netobj (XDR *xdrs, netobj *objp)
{
	 if (!xdr_bytes (xdrs, (char **)&objp->n_bytes, (u_int *) &objp->n_len, MAXNETOBJ_SZ))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_fsh_mode (XDR *xdrs, fsh_mode *objp)
{
	 if (!xdr_enum (xdrs, (enum_t *) objp))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_fsh_access (XDR *xdrs, fsh_access *objp)
{
	 if (!xdr_enum (xdrs, (enum_t *) objp))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_nlm4_stats (XDR *xdrs, nlm4_stats *objp)
{
	 if (!xdr_enum (xdrs, (enum_t *) objp))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_nlm4_stat (XDR *xdrs, nlm4_stat *objp)
{
	 if (!xdr_nlm4_stats (xdrs, &objp->stat))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_nlm4_holder (XDR *xdrs, nlm4_holder *objp)
{
	 if (!xdr_bool (xdrs, &objp->exclusive))
		 return FALSE;
	 if (!xdr_uint32_t (xdrs, &objp->svid))
		 return FALSE;
	 if (!xdr_netobj (xdrs, &objp->oh))
		 return FALSE;
	 if (!xdr_uint64_t (xdrs, &objp->l_offset))
		 return FALSE;
	 if (!xdr_uint64_t (xdrs, &objp->l_len))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_nlm4_lock (XDR *xdrs, nlm4_lock *objp)
{
	 if (!xdr_string (xdrs, &objp->caller_name, MAXNAMELEN))
		 return FALSE;
	 if (!xdr_netobj (xdrs, &objp->fh))
		 return FALSE;
	 if (!xdr_netobj (xdrs, &objp->oh))
		 return FALSE;
	 if (!xdr_uint32_t (xdrs, &objp->svid))
		 return FALSE;
	 if (!xdr_uint64_t (xdrs, &objp->l_offset))
		 return FALSE;
	 if (!xdr_uint64_t (xdrs, &objp->l_len))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_nlm4_share (XDR *xdrs, nlm4_share *objp)
{
	 if (!xdr_string (xdrs, &objp->caller_name, MAXNAMELEN))
		 return FALSE;
	 if (!xdr_netobj (xdrs, &objp->fh))
		 return FALSE;
	 if (!xdr_netobj (xdrs, &objp->oh))
		 return FALSE;
	 if (!xdr_fsh_mode (xdrs, &objp->mode))
		 return FALSE;
	 if (!xdr_fsh_access (xdrs, &objp->access))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_nlm4_testrply (XDR *xdrs, nlm4_testrply *objp)
{
	 if (!xdr_nlm4_stats (xdrs, &objp->stat))
		 return FALSE;
	switch (objp->stat) {
	case nlm4_denied:
		 if (!xdr_nlm4_holder (xdrs, &objp->nlm4_testrply_u.holder))
			 return FALSE;
		break;
	default:
		break;
	}
	return TRUE;
}

bool_t
xdr_nlm4_testres (XDR *xdrs, nlm4_testres *objp)
{
	 if (!xdr_netobj (xdrs, &objp->cookie))
		 return FALSE;
	 if (!xdr_nlm4_testrply (xdrs, &objp->stat))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_nlm4_testargs (XDR *xdrs, nlm4_testargs *objp)
{
	 if (!xdr_netobj (xdrs, &objp->cookie))
		 return FALSE;
	 if (!xdr_bool (xdrs, &objp->exclusive))
		 return FALSE;
	 if (!xdr_nlm4_lock (xdrs, &objp->alock))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_nlm4_res (XDR *xdrs, nlm4_res *objp)
{
	 if (!xdr_netobj (xdrs, &objp->cookie))
		 return FALSE;
	 if (!xdr_nlm4_stat (xdrs, &objp->stat))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_nlm4_lockargs (XDR *xdrs, nlm4_lockargs *objp)
{
	 if (!xdr_netobj (xdrs, &objp->cookie))
		 return FALSE;
	 if (!xdr_bool (xdrs, &objp->block))
		 return FALSE;
	 if (!xdr_bool (xdrs, &objp->exclusive))
		 return FALSE;
	 if (!xdr_nlm4_lock (xdrs, &objp->alock))
		 return FALSE;
	 if (!xdr_bool (xdrs, &objp->reclaim))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->state))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_nlm4_cancargs (XDR *xdrs, nlm4_cancargs *objp)
{
	 if (!xdr_netobj (xdrs, &objp->cookie))
		 return FALSE;
	 if (!xdr_bool (xdrs, &objp->block))
		 return FALSE;
	 if (!xdr_bool (xdrs, &objp->exclusive))
		 return FALSE;
	 if (!xdr_nlm4_lock (xdrs, &objp->alock))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_nlm4_unlockargs (XDR *xdrs, nlm4_unlockargs *objp)
{
	 if (!xdr_netobj (xdrs, &objp->cookie))
		 return FALSE;
	 if (!xdr_nlm4_lock (xdrs, &objp->alock))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_nlm4_shareargs (XDR *xdrs, nlm4_shareargs *objp)
{
	 if (!xdr_netobj (xdrs, &objp->cookie))
		 return FALSE;
	 if (!xdr_nlm4_share (xdrs, &objp->share))
		 return FALSE;
	 if (!xdr_bool (xdrs, &objp->reclaim))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_nlm4_shareres (XDR *xdrs, nlm4_shareres *objp)
{
	 if (!xdr_netobj (xdrs, &objp->cookie))
		 return FALSE;
	 if (!xdr_nlm4_stats (xdrs, &objp->stat))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->sequence))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_nlm4_freeallargs (XDR *xdrs, nlm4_freeallargs *objp)
{
        if (!xdr_string (xdrs, &objp->name, LM_MAXSTRLEN))
                return FALSE;
        if (!xdr_uint32_t (xdrs, &objp->state))
                return FALSE;
        return TRUE;
}


/*
bool_t
xdr_nlm_sm_status (XDR *xdrs, nlm_sm_status *objp)
{
	 if (!xdr_string (xdrs, &objp->mon_name, LM_MAXSTRLEN))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->state))
		 return FALSE;
	 if (!xdr_opaque (xdrs, objp->priv, 16))
		 return FALSE;
	return TRUE;
}
*/