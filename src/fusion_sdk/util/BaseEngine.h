////////////////////////////////////////////////////////////////
//
// Copyright (C) 2005 Affymetrix, Inc.
//
// This program is free software; you can redistribute it and/or modify 
// it under the terms of the GNU General Public License (version 2) as 
// published by the Free Software Foundation.
// 
// This program is distributed in the hope that it will be useful, 
// but WITHOUT ANY WARRANTY; without even the implied warranty of 
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
// General Public License for more details.
// 
// You should have received a copy of the GNU General Public License 
// along with this program;if not, write to the 
// 
// Free Software Foundation, Inc., 
// 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
//
////////////////////////////////////////////////////////////////

/**
 * @file   BaseEngine.h
 * @author Alan Williams
 * @date   Mon Jun 23 14:57:34 PDT 2008
 * 
 * @brief base engine base class
 */
#ifndef _BASEENGINE_H_
#define _BASEENGINE_H_

//
#include "util/Options.h"
#include "util/PgOptions.h"
#include "util/Util.h"
//
#include "apt/apt.h"
//
#include <cstring>
#include <list>
#include <string>
#include <vector>
//

/**
   @brief Base class for analysis engines

*/
class APTLIB_API BaseEngine : public Options {

public:

  virtual std::string getEngineName() = 0;

  /**
   * Constructor
   */
  BaseEngine();

  /**
   * Constructor
   * @param argv - vector of args to parse
   */
  BaseEngine ( char * argv[] );

  /**
   * Destructor
   */
  virtual ~BaseEngine();

  /** 
   * Run the engine -- entry point to run the engine
   * Will call Verbose::out() and Err::errAbort().
   */
  void run();

  /**
   * Get the name of the Engine
   */
  std::string getProgName();

  /**
   * Check the validity of options specified
   */
  void checkOptions();

  /**
   * Query available disk space and compare it to estimated disk space
   * needed for temporary and CHP files
   */
  void checkDiskSpace();

  /**
   * Swap the option value to include the full path if found
   * @param option
   */
  void setLibFileOpt(const std::string &option);

protected:
  /** 
   * Engine implementations in child
   * Will call Verbose::out() and Err::errAbort().
   */
  virtual void runImp() {}
  virtual void checkOptionsImp() {}
  virtual void checkDiskSpaceImp() {}
  virtual void extraHelp() {}

  void printEngineOptions() {
      printOptions(getEngineName() + ": ");
  }

  void printEngineOptions(const std::string &label) {
      printOptions(getEngineName() + ": " + label);
  }

  void makeTempDir(std::string temp_dir);
  
  void removeTempDir(std::string temp_dir);

private:
  virtual void defineOptions();
  virtual void defineStates();
  bool m_OptionsChecked;
  bool m_DiskChecked;
  /*! flag to indicate if tempdir should be deleted at end of run */
  bool m_created_new_tempdir;

};


/*! A class used to self register engine data classes. */
class APTLIB_API EngineReg
{
public:
    /*! Constructor 
     * @param engName The name of the engine to create.
     */
    EngineReg(const std::string &engName);

    /*! Destructor */
    virtual ~EngineReg();

    /*! Creates an engine object.
     * @param name The name of the engine to create.
     * @return A pointer to the engine. NULL if the failed.
     */
    static BaseEngine *CreateEngine(const std::string &name);

    /*! Gets the list of all registered engines.
     * @return The list of registered engines.
     */
    static std::list<std::string> GetEngineNames();

private:

    /*! Makes an engine data object.
     * @return The engine data object.
     */
    virtual BaseEngine *MakeObject() = 0;

    /*! A pointer to the first registered engine. */
    static EngineReg *m_Head;

    /*! A pointer to the next registered engine. */
    EngineReg *m_Next;

    /*! The name of the engine. */
    std::string name;

};


#endif /* _BASEENGINE_H_ */
