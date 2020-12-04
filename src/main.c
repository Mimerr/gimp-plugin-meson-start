#include <libgimp/gimp.h>

static void query (void);
static void run   (const gchar      *name,
                   gint              nparams,
                   const GimpParam  *param,
                   gint             *nreturn_vals,
                   GimpParam       **return_vals);

GimpPlugInInfo PLUG_IN_INFO = {
  NULL,
  NULL,
  query,
  run
};

MAIN()

/**
 * Sets up the plugin's procedures and arguments when it is first loaded.
 */
static void query(void) {
  static GimpParamDef args[] = {
    { GIMP_PDB_INT32, "run-mode", "Run mode" },
    { GIMP_PDB_IMAGE, "image", "Input image" },
    { GIMP_PDB_DRAWABLE, "drawable", "Input drawable" }
  };

  gimp_install_procedure(
    // Procedure name.
    "plug-in-proc-name",
    // Description.
    "Describe the plugin here.",
    // Help text.
    "Write plugin instructions here.",
    // Author.
    "Author Name",
    // Copyright.
    "Copyright Creator/Company Name",
    // Date.
    "Date of creation",
    // Menu text.
    "Menu Label...",
    // Operable image types.
    "RGB*, GRAY*",
    // Plugin type.
    GIMP_PLUGIN,
    // Arguments, return values, and amounts.
    G_N_ELEMENTS (args), 0,
    args, NULL
  );

  // Register the procedure installed above to a place on the menu bar.
  gimp_plugin_menu_register("plug-in-proc-name", "<Image>/Filter/Plugin");
}

/**
 * The main function. Kicks off the action when the menu item is selected.
 *
 * @param name Name of plugin.
 * @param nparams Number of parameters given to plugin.
 * @param param The gimp parameters.
 * @param nreturn_vals Number of return values.
 * @param return_vals The return values.
 */
static void run(const gchar *name, gint nparams, const GimpParam *param,
gint *nreturn_vals, GimpParam **return_vals) {
  static GimpParam  values[1];
  GimpPDBStatusType status = GIMP_PDB_SUCCESS;
  GimpRunMode       run_mode;
  *nreturn_vals = 1;
  *return_vals  = values;
  values[0].type = GIMP_PDB_STATUS;
  values[0].data.d_status = status;
  run_mode = param[0].data.d_int32; // Get run mode.

  // TODO create plugin functionality here.
}
