//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose:
//
//=============================================================================//

#ifndef WEAPON_FRYINGPAN_H
#define WEAPON_FRYINGPAN_H

#include "basebludgeonweapon.h"

#if defined( _WIN32 )
#pragma once
#endif

#ifdef HL2MP
#error weapon_crowbar.h must not be included in hl2mp. The windows compiler will use the wrong class elsewhere if it is.
#endif

#define	FRYINGPAN_RANGE		75.0f
#define	FRYINGPAN_REFIRE	1.0f

//-----------------------------------------------------------------------------
// CWeaponFryingPan
//-----------------------------------------------------------------------------

class CWeaponFryingPan : public CBaseHLBludgeonWeapon
{
public:
	DECLARE_CLASS( CWeaponFryingPan, CBaseHLBludgeonWeapon );

	DECLARE_SERVERCLASS();
	DECLARE_ACTTABLE();

	CWeaponFryingPan();

	float		GetRange(void)			{ return	FRYINGPAN_RANGE; }
	float		GetFireRate(void)		{ return	FRYINGPAN_REFIRE; }

	void		AddViewKick( void );
	float		GetDamageForActivity( Activity hitActivity );

	virtual int WeaponMeleeAttack1Condition( float flDot, float flDist );
	void		SecondaryAttack( void )	{	return;	}

	// Animation event
	virtual void Operator_HandleAnimEvent( animevent_t *pEvent, CBaseCombatCharacter *pOperator );

private:
	// Animation event handlers
	void HandleAnimEventMeleeHit( animevent_t *pEvent, CBaseCombatCharacter *pOperator );
};

#endif // WEAPON_FRYINGPAN_H
