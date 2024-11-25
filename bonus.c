#include "so_long.h"

void display_movements(t_game *game)
{
    char *movement_text;

    // Convertit le nombre de mouvements en chaîne de caractères
    movement_text = ft_itoa(game->player.movements);
    if (!movement_text)
        return;

    // Affiche le texte à une position donnée
    mlx_string_put(game->mlx_ptr, game->win_ptr, 10, 20, 0xFFFFFF, "Number of Moves: ");
    mlx_string_put(game->mlx_ptr, game->win_ptr, 110, 20, 0xFFFFFF, movement_text);

    // Libère la chaîne de caractères générée par ft_itoa
    free(movement_text);
}