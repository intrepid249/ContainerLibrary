#pragma once

namespace ms {
	template <typename T, typename A>
	void merge(A*, T, T, T);

	template <typename T, typename A>
	void merge_sort(A *a, T low, T high) {
		int mid;
		if (low < high) {
			mid = (low + high) / 2;
			merge_sort(a, low, mid);
			merge_sort(a, mid + 1, high);
			merge(a, low, high, mid);
		}
		return;
	}

	template <typename T, typename A>
	void merge(A *a, T low, T high, T mid) {
		A c[50];
		T i, j, k;
		i = k = low;
		j = mid + 1;

		while (i <= mid && j <= high) {
			if (a[i] < a[j])
				c[k++] = a[i++];
			else
				c[k++] = a[j++];
		}

		while (i <= mid) {
			c[k++] = a[i++];
		}

		while (j <= high) {
			c[k++] = a[j++];
		}

		for (i = low; i < k; i++) {
			a[i] = c[i];
		}
	}
}