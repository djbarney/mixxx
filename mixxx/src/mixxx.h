/***************************************************************************
                          mixxx.h  -  description
                             -------------------
    begin                : Mon Feb 18 09:48:17 CET 2002
    copyright            : (C) 2002 by Tue and Ken Haste Andersen
    email                :
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef MIXXX_H
#define MIXXX_H

// include files for QT
#include <qmainwindow.h>
#include <qaction.h>
#include <qmenubar.h>
#include <qpopupmenu.h>
#include <qtoolbutton.h>
#include <qwhatsthis.h>
#include <qstring.h>
#include <qstringlist.h>
#include <qpixmap.h>
#include <qmsgbox.h>
#include <qfiledialog.h>
#include <qprinter.h>
#include <qpainter.h>
#include <qpoint.h>
#include <qapplication.h>
#include <vector>
#include <qstringlist.h>

// application specific includes
#include "defs.h"
#include "mixxxview.h"
#include "enginebuffer.h"
#include "enginechannel.h"
#include "enginemaster.h"
#include "controlobject.h"
#include "dlgpreferences.h"
#include "trackplaylist.h"

class WVisual;
class Track;
class TrackInfoObject;
class PlayerProxy;
class WaveSummary;
class QSplashScreen;

/**
  * This Class is the base class for Mixxx. It sets up the main
  * window and providing a menubar.
  * For the main view, an instance of class MixxxView is
  * created which creates your view.
  */
class MixxxApp : public QMainWindow
{
  Q_OBJECT

  public:
    /** Construtor. files is a list of command line arguments */
    MixxxApp(QApplication *app, QStringList files, QSplashScreen *pSplash, QString qLogFileName);
    /** destructor */
    ~MixxxApp();
    /** initializes all QActions of the application */
    void initActions();
    /** initMenuBar creates the menu_bar and inserts the menuitems */
    void initMenuBar();
    /** overloaded for Message box on last window exit */
    bool queryExit();
  public slots:

    /** Opens a file in player 1 */
    void slotFileOpen();
    /** exits the application */
    void slotFileQuit();
    /** toggle audio beat marks */
    void slotOptionsBeatMark(bool toggle);
    /** toogle full screen mode */
    void slotOptionsFullScreen(bool toggle);
    /** Preference dialog */
    void slotOptionsPreferences();
    /** shows an about dlg*/
    void slotHelpAbout();
    /** Change of file to play */
    //void slotChangePlay(int,int,int, const QPoint &);
  private:
    /** view is the main widget which represents your working area. The View
     * class should handle all events of the view widget.  It is kept empty so
     * you can create your view according to your application's needs by
     * changing the view class.
     */
    MixxxView *view;
    /** Pointer to waveform summary generator */
    WaveSummary *m_pWaveSummary;

    QApplication *app;
    EngineObject *engine;
    EngineBuffer *buffer1, *buffer2;
    EngineChannel *channel1, *channel2;
    EngineMaster *master;
    PlayerProxy *player;
    MidiObject *midi;
    ControlObject *control;
    ConfigObject<ConfigValue> *config;
    /** Pointer to active midi configuration */
    ConfigObject<ConfigValueMidi> *midiconfig;
    /** Pointer to active keyboard configuration */
    ConfigObject<ConfigValueKbd> *kbdconfig;
    /** Pointer to track object */
    Track *m_pTrack;
    /** file_menu contains all items of the menubar entry "File" */
    QPopupMenu *fileMenu;
    /** edit_menu contains all items of the menubar entry "Edit" */
    QPopupMenu *editMenu;
    /** playlist menu */
    QPopupMenu *playlistsMenu;
    /** options_menu contains all items of the menubar entry "Options" */
    QPopupMenu *optionsMenu;
    /** view_menu contains all items of the menubar entry "View" */
    QPopupMenu *viewMenu;
    /** view_menu contains all items of the menubar entry "Help" */
    QPopupMenu *helpMenu;
    /** actions for the application initialized in initActions() and used to en/disable them
      * according to your needs during the program */
    QAction *fileNew;
    QAction *fileOpen;
    QAction *fileSave;
    QAction *fileSaveAs;
    QAction *fileClose;
    QAction *filePrint;
    QAction *fileQuit;

    QAction *editCut;
    QAction *editCopy;
    QAction *editPaste;

    QAction *playlistsNew;
    QAction *playlistsImport;
    QAction **playlistsList;
    int m_iNoPlaylists;

    QAction *optionsBeatMark;
    QAction *optionsFullScreen;
    QAction *optionsPreferences;
    /** Pointer to preference dialog */
    DlgPreferences *prefDlg;

    QAction *helpAboutApp;
};
#endif

