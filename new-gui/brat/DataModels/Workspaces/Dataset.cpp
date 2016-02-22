/*
* This file is part of BRAT
*
* BRAT is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License
* as published by the Free Software Foundation; either version 2
* of the License, or (at your option) any later version.
*
* BRAT is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

#include "new-gui/brat/stdafx.h"
#include "new-gui/Common/QtUtilsIO.h"
#include "new-gui/Common/tools/Trace.h"
#include "new-gui/Common/tools/Exception.h"

#include "libbrathl/Tools.h"

#include "WorkspaceSettings.h"
#include "Dataset.h"


//----------------------------------------
std::string CDataset::GetFieldSpecificUnit( const std::string& key )
{
	return m_fieldSpecificUnit.Exists( key );
}
//----------------------------------------
void CDataset::SetFieldSpecificUnit( const std::string& key, const std::string& value )
{
	m_fieldSpecificUnit.Erase( key );
	m_fieldSpecificUnit.Insert( key, value, false );
}
//----------------------------------------
bool CDataset::CtrlFiles( std::vector< std::string > &v )
{
	for ( CProductList::iterator it = m_files.begin(); it != m_files.end(); it++ )
	{
		if ( !IsFile( it->c_str() ) )
			v.push_back(*it);
	}
	return v.empty();
}
//----------------------------------------
CProduct* CDataset::SetProduct()
{
	if ( m_files.size() <= 0 )
		return NULL;

	return SetProduct( m_files.begin()->c_str() );
}
//----------------------------------------
CProduct* CDataset::SetProduct( const std::string& fileName )
{
	CProduct* product = NULL;
	try
	{
		product = CProduct::Construct( fileName );
        product->SetFieldSpecificUnits( m_fieldSpecificUnit );
        product->Open( fileName );
	}
	catch ( const CException& e )
	{
		UNUSED( e );

		if ( product != NULL )
		{
			delete product;
			product = NULL;
		}
		throw;
	}

	return product;
}
//----------------------------------------
bool CDataset::SaveConfig( CWorkspaceSettings *config ) const
{
	assert__( config );			// v4 test why this could be null
	//return !config || config->SaveConfig( this );

	return config->SaveConfig( this );
}
bool CDataset::LoadConfig( CWorkspaceSettings *config )
{
	assert__( config );			// v4 test why this could be null
	//return !config || config->LoadConfig( this );

	return config->LoadConfig( this );
}
//----------------------------------------
void CDataset::Dump( std::ostream& fOut /* = std::cerr */ )
{
	if ( !CTrace::IsTrace() )
		return;

	fOut << "==> Dump a CDataset Object at " << this << std::endl;

	m_files.Dump( fOut );
	fOut << "==> END Dump a CDataset Object at " << this << std::endl;

	fOut << std::endl;
}

