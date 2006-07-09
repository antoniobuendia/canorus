/*****************************************************************************/
/*									     */
/* This program is free software; you can redistribute it and/or modify it   */
/* under the terms of the GNU General Public License as published by the     */ 
/* Free Software Foundation; version 2 of the License.	                     */
/*									     */
/* This program is distributed in the hope that it will be useful, but       */
/* WITHOUT ANY WARRANTY; without even the implied warranty of                */ 
/* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General  */
/* Public License for more details.                                          */
/*									     */
/* You should have received a copy of the GNU General Public License along   */
/* with this program; (See "LICENSE.GPL"). If not, write to the Free         */
/* Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA        */
/* 02111-1307, USA.				                             */
/*									     */
/*---------------------------------------------------------------------------*/
/*									     */
/*		Reinhard Katzmann, GERMANY			             */
/*		reinhard@suamor.de					     */
/*									     */
/*		Matevž Jekovec, SLOVENIA			             */
/*		matevz.jekovec@guest.arnes.si				     */
/*									     */
/*****************************************************************************/

#include "ui_mainwin.h"

#include "document.h"

class CAMainWin: public QMainWindow
{
	Q_OBJECT

public:
	CAMainWin(QMainWindow *oParent = 0);
	~CAMainWin() {};
	
	void newDocument();

private slots:
	//////////////////////////////////////////////////////
	//Menu bar actions
	//////////////////////////////////////////////////////
	//View menu
	void processFullScreenEvent(bool);
	
	//Window menu
	void processSplitHorizontallyEvent(bool);
	void processSplitVerticallyEvent(bool);
	void processUnsplitEvent(bool);
	void processNewViewPortEvent(bool);

private:
	void connectActions();	///Connect the menu and other actions with its appropriate slots
	
    Ui::MainWindow oMainWin;
    CADocument _document;
};