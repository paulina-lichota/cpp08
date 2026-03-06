/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 19:00:21 by plichota          #+#    #+#             */
/*   Updated: 2026/03/06 20:12:51 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// uso container sequenziali quindi posso usare std::find (uso .begin() e .end() per iterare)
// ritorno iteratore di fine (posizione dopo l'ultimo elemento del container) se non trovato
// non uso throw perche' nei sequenziali non si usano eccezioni
template <typename T>
typename T::iterator easyfind(T &a, int b)
{
    // find restituisce un iteratore (funziona simile a puntatore)
    return std::find(a.begin(), a.end(), b);
}